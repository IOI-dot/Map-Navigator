#include "navigate.h"
#include "ui_navigate.h"
#include "welcomepage.h"
#include "graphitem.h"
#include "dijkstra.h"

Navigate::Navigate(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Navigate)
{
    ui->setupUi(this);
    ui->errorlabel->setVisible(false);
    ui->errorlabel_2->setVisible(false);
    ui->theShortest->setVisible(false);
    ui->thePath->setVisible(false);
    ui->path->setVisible(false);

    ui->sourcebox->addItem("");
    ui->sourcebox->setCurrentIndex(0);

    ui->destinationbox->addItem("");
    ui->destinationbox->setCurrentIndex(0);

    for (int i = 0; i < graph.getSize(); ++i) {
        ui->sourcebox->addItem(graph.getCityName(i));
        ui->destinationbox->addItem(graph.getCityName(i));
    }

}

Navigate::~Navigate()
{
    delete ui;
}

void Navigate::on_back_clicked()
{
    this->hide();
    welcomePage* welcome = new welcomePage(this);
    welcome->show();
}


void Navigate::on_go_clicked() {
    QString source = ui->sourcebox->currentText();
    QString dest = ui->destinationbox->currentText();

    if (source.isEmpty() || dest.isEmpty()) {
        ui->errorlabel_2->setText("Please select two cities.");
        ui->errorlabel_2->setVisible(true);
        ui->errorlabel->setVisible(false);
        ui->theShortest->setVisible(false);
        ui->thePath->setVisible(false);
        ui->path->setVisible(false);
        return;
    }

    if (source == dest) {
        ui->errorlabel->setVisible(true);
        ui->errorlabel_2->setVisible(false);
        ui->theShortest->setVisible(false);
        ui->thePath->setVisible(false);
        ui->path->setVisible(false);
        return;
    }

    ui->errorlabel->setVisible(false);
    ui->errorlabel_2->setVisible(false);

    location = source;
    destination = dest;

    Dijkstra dijkstra;
    auto result = dijkstra.shortestPath(graph, location, destination);

    if (result.first.empty() || result.second == -1) {
        ui->theShortest->setText("No path found between " + location + " and " + destination + ".");
        ui->thePath->setVisible(false);
        ui->path->setVisible(false);
        ui->theShortest->setVisible(true);
        return;
    }

    ui->theShortest->setText("The shortest distance between " + location + " and " + destination + " is " + QString::number(result.second) + " km.");
    ui->theShortest->setVisible(true);

    QString pathStr;
    for (int i = 0; i < result.first.size(); ++i) {
        pathStr += result.first[i];
        if (i != result.first.size() - 1) {
            pathStr += " → ";
        }
    }

    ui->path->setText(pathStr);
    ui->thePath->setVisible(true);
    ui->path->setVisible(true);
}

