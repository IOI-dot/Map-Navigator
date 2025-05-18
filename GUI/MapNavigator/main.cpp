#include "welcomepage.h"
#include "graph.h"
#include "graphitem.h"
#include "file_reader.h"
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    FileReader x;
    x.loadFromFile("C:/Users/Omar/CLionProjects/Map-Navigator/city_connections_dataset.txt", graph);
    // welcomePage w;
    MainWindow w;
    w.show();

    return a.exec();

}
