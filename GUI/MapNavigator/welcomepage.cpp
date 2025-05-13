#include "welcomepage.h"
#include "ui_welcomepage.h"
#include "cities.h"
#include "paths.h"
#include "navigate.h"
#include "instructions.h"
#include "graphitem.h"
#include "display.h"
#include "file_reader.h"
#include <QApplication>

welcomePage::welcomePage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::welcomePage)
{
    ui->setupUi(this);
}

welcomePage::~welcomePage()
{
    delete ui;
}


void welcomePage::on_cities_clicked()
{
    this->hide();
    Cities* manageCities = new Cities(this);
    manageCities->show();
}


void welcomePage::on_paths_clicked()
{
    this->hide();
    Paths* managePaths = new Paths(this);
    managePaths->show();
}


void welcomePage::on_navigate_clicked()
{
    this->hide();
    Navigate* navigation = new Navigate(this);
    navigation->show();
}


void welcomePage::on_quit_clicked()
{
    // FileReader::saveToFile("../MapNavigator/city_connections_dataset.txt");
    QApplication::quit();
}


void welcomePage::on_pushButton_5_clicked()
{
    this->hide();
    Instructions* help = new Instructions(this);
    help->show();
}


void welcomePage::on_display_clicked()
{
    this->hide();
    display* Display = new display(this);
    Display->show();
}

