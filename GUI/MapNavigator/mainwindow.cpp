#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "graphitem.h"
#include "dijkstra.h"
#include <QtMath>
#include <QGraphicsEllipseItem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    ui->graphicsView->setRenderHint(QPainter::Antialiasing);

    showGraph();

    // ui->theShortest->setVisible(false);
    // ui->thePath->setVisible(false);
    // ui->path->setVisible(false);

    ui->sourcebox->addItem("");
    ui->sourcebox->setCurrentIndex(0);

    ui->sourcebox2->addItem("");
    ui->sourcebox2->setCurrentIndex(0);

    for (int i = 0; i < graph.getSize(); ++i) {
        ui->sourcebox->addItem(graph.getCityName(i));
        ui->sourcebox2->addItem(graph.getCityName(i));
    }

    ui->go->setEnabled(false);

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

    QString source = ui->sourcebox->currentText();
    QString dest = ui->sourcebox2->currentText();

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

    // QString pathStr;
    // for (int i = 0; i < result.first.size(); ++i) {
    //     pathStr += result.first[i];
    //     if (i != result.first.size() - 1) {
    //         pathStr += " → ";
    //     }
    // }

    for (int i = 0; i < path.size() - 1; i++) {
        int from = graph.getCityIndex(path[i]);
        int to = graph.getCityIndex(path[i+1]);

        if (from != -1 && to != -1) {
            QGraphicsLineItem* line = scene->addLine(QLineF(cityPositions[from], cityPositions[to]), QPen(Qt::green));
            edgeLines.append(line);;

        }
    }

    for (const QString& cityName : path) {
        int index = graph.getCityIndex(cityName);
        if (index != -1 && index < cities.size()) {
            cities[index]->setBrush(Qt::white);
        }
    }

    ui->distance->setText("Total Distance: \n " + QString::number(distance) +  " km.");
    ui->distance->show();

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

    // FileReader::saveToFile("../MapNavigator/city_connections_dataset.txt");
    QApplication::quit();

}


void MainWindow::on_reset_clicked()
{
    showGraph();
}

