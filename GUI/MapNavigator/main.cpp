#include "welcomepage.h"
#include "graph.h"
#include "graphitem.h"
#include "file_reader.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    FileReader x;
    x.loadFromFile("../MapNavigator/city_connections_dataset.txt", graph);
    welcomePage w;
    w.show();

    return a.exec();

}
