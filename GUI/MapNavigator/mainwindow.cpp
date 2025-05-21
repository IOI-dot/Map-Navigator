#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "graphitem.h"
#include "dijkstra.h"
#include <QtMath>
#include <QGraphicsEllipseItem>
#include <QMessageBox>
#include <QKeyEvent>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    ui->graphicsView->setRenderHint(QPainter::Antialiasing);

    showGraph();

    ui->sourcebox->addItem("");
    ui->sourcebox->setCurrentIndex(0);

    ui->sourcebox2->addItem("");
    ui->sourcebox2->setCurrentIndex(0);

    for (int i = 0; i < graph.getSize(); ++i) {
        ui->sourcebox->addItem(graph.getCityName(i));
        ui->sourcebox2->addItem(graph.getCityName(i));
    }

    ui->go->setEnabled(false);
    ui->sourcebox->setEditable(true);
    ui->sourcebox2->setEditable(true);
    QSet<QString> citySet;
    for (int i = 0; i < graph.getSize(); ++i) {
        citySet.insert(graph.getCityName(i));
    }
    spellChecker = new SpellChecker(citySet);
    ui->sourcebox->installEventFilter(this);
    ui->sourcebox2->installEventFilter(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::showGraph() {
    scene->clear();
    cityPositions.clear();
    edgeLines.clear();
    cities.clear();
    ui->distance->hide();

    radiusX = 250;
    radiusY = 175;
    nodeSize = 30;


    for (int i = 0; i < graph.getSize(); i++) {
        qreal angle = 2.0 * M_PI * (i/static_cast<qreal>(graph.getSize()));
        qreal x = radiusX * qCos(angle);
        qreal y = radiusY * qSin(angle);

        QRectF rect((x - nodeSize / 2), (y - nodeSize / 2), nodeSize, nodeSize);
        QColor color(128, 162, 146);
        QBrush brush(color);
        QGraphicsEllipseItem* city = scene->addEllipse(rect, QPen(Qt::white), brush);
        city->setZValue(1);
        cities.append(city);
        QPointF center = city->sceneBoundingRect().center();

        cityPositions.push_back(center);

        QGraphicsTextItem* name = scene->addText(graph.getCityName(i));
        name->setZValue(1);
        name->setDefaultTextColor(Qt::white);
        name->setPos((x + nodeSize/2), (y + nodeSize/2));

    }

    for (int i = 0; i < graph.getSize(); i++) {
        const auto& edges = graph.getEdges(i);

        for (int j = 0; j < edges.get_size(); j++) {
            int toCity = edges[j].to;

            if (toCity < 0 || toCity >= graph.getSize())
                continue;


            QPointF p1 = cityPositions[i];
            QPointF p2 = cityPositions[toCity];

            QGraphicsLineItem* line = scene->addLine(QLineF(p1, p2), QPen(Qt::darkCyan));
            line->setZValue(0);
            edgeLines.append(line);
        }
    }



}

void MainWindow::on_go_clicked() {
    for (auto city : cities) {
        city->setBrush(QColor(128, 162, 146));
    }

    QString source = ui->sourcebox->currentText().trimmed();
    QString dest = ui->sourcebox2->currentText().trimmed();


    if (graph.getCityIndex(source) == -1) {
        QString suggestion = spellChecker->findClosestMatch(source);
        if (suggestion != source) {
            QMessageBox::StandardButton reply;
            reply = QMessageBox::question(this, "Did you mean...",
                                          "City \"" + source + "\" not found.\nDid you mean \"" + suggestion + "\"?",
                                          QMessageBox::Yes | QMessageBox::No);

            if (reply == QMessageBox::Yes) {
                source = suggestion;
                int suggestionIndex = ui->sourcebox->findText(suggestion);
                if (suggestionIndex != -1) {
                    ui->sourcebox->setCurrentIndex(suggestionIndex); // Select valid one already in list
                }
            } else {
                return; // Stop if user rejects suggestion
            }
        }
    }


    if (graph.getCityIndex(dest) == -1) {
        QString suggestion = spellChecker->findClosestMatch(dest);
        if (suggestion != dest) {
            QMessageBox::StandardButton reply;
            reply = QMessageBox::question(this, "Did you mean...",
                                          "City \"" + dest + "\" not found.\nDid you mean \"" + suggestion + "\"?",
                                          QMessageBox::Yes | QMessageBox::No);

            if (reply == QMessageBox::Yes) {
                dest = suggestion;
                ui->sourcebox2->setCurrentText(suggestion);
            } else {
                return;
            }
        }
    }

    location = source;
    destination = dest;

    Dijkstra dijkstra;
    auto result = dijkstra.shortestPath(graph, location, destination);
    auto path = result.first;
    double distance = result.second;

    for (auto line : edgeLines) {
        scene->removeItem(line);
        delete line;
    }

    edgeLines.clear();

    if (distance == -1 || path.empty()) {
        // No path found
        QMessageBox::warning(this, "No Path Found",
                             "No path exists between \"" + location + "\" and \"" + destination + "\".");

        ui->distance->setText("Total Distance:\nN/A");
        ui->pathLabel->setText("Path Taken:\nNo available path.");
        ui->pathLabel->setVisible(true);
        showGraph();
        return; //no path to draw
    }
    for (int i = 0; i < path.size() - 1; i++) {
        int from = graph.getCityIndex(path[i]);
        int to = graph.getCityIndex(path[i + 1]);

        if (from != -1 && to != -1) {
            QGraphicsLineItem* line = scene->addLine(QLineF(cityPositions[from], cityPositions[to]), QPen(Qt::green));
            edgeLines.append(line);
        }
    }

    for (const QString& cityName : path) {
        int index = graph.getCityIndex(cityName);
        if (index != -1 && index < cities.size()) {
            cities[index]->setBrush(Qt::white);
        }
    }

    // Show distance
    ui->distance->setText("Total Distance:\n" + QString::number(distance) + " km.");
    ui->distance->show();

    // Show path
    QString pathStr;
    for (int i = 0; i < path.size(); ++i) {
        pathStr += path[i];
        if (i != path.size() - 1)
            pathStr += " → ";
    }

    // Set the text
    ui->pathLabel->setText("Path Taken:\n" + pathStr);

    // Make font bold and bigger
    QFont font = ui->pathLabel->font();
    font.setBold(true);
    font.setPointSize(12);
    ui->pathLabel->setFont(font);
    ui->pathLabel->setStyleSheet("QLabel { color : darkblue; }");
    ui->pathLabel->setVisible(true);
}

void MainWindow::on_sourcebox2_currentIndexChanged(int index) {
    source2 = index;

    if (source2 != 0 && source1 != 0)
        ui->go->setEnabled(true);
    else
        ui->go->setEnabled(false);
}


void MainWindow::on_sourcebox_currentIndexChanged(int index) {
    source1 = index;

    if (source2 != 0 && source1 != 0)
        ui->go->setEnabled(true);
    else
        ui->go->setEnabled(false);
}


void MainWindow::on_quit_clicked()
{
    QApplication::quit();

}


void MainWindow::on_reset_clicked()
{
    showGraph();
}
bool MainWindow::eventFilter(QObject *obj, QEvent *event) {
    if (event->type() == QEvent::KeyPress) {
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
        if (keyEvent->key() == Qt::Key_Return || keyEvent->key() == Qt::Key_Enter) {
            if (obj == ui->sourcebox) {
                // Move focus to sourcebox2 when Enter pressed in sourcebox
                ui->sourcebox2->setFocus();
                return true; // Event handled
            } else if (obj == ui->sourcebox2) {
                // Move focus to go button when Enter pressed in sourcebox2
                ui->go->setFocus();
                return true; // Event handled
            }
        }
    }
    return QMainWindow::eventFilter(obj, event);
}
