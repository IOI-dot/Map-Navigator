#ifndef DISPLAY_H
#define DISPLAY_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "Dynamic_Array.h"

namespace Ui {
class display;
}

class display : public QMainWindow
{
    Q_OBJECT

public:
    explicit display(QWidget *parent = nullptr);
    ~display();

private slots:
    void on_back_clicked();

private:
    Ui::display *ui;
    QGraphicsScene* scene;
    int radius;
    int nodeSize;
    int graphSize;
    DynamicArray<QPointF> cityPositions;
    void showGraph();
};

#endif // DISPLAY_H
