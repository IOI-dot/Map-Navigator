#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "Dynamic_Array.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QGraphicsScene* scene;
    int radius;
    int nodeSize;
    int graphSize;
    DynamicArray<QPointF> cityPositions;
    void showGraph();
};

#endif // MAINWINDOW_H
