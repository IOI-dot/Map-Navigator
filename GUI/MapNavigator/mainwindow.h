#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include "Dynamic_Array.h"
#include "spellchecker.h"
#include "graphitem.h"
#include "dijkstra.h"
#include <QtMath>
#include <QGraphicsEllipseItem>
#include <QMessageBox>
#include <QKeyEvent>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
protected:
    bool eventFilter(QObject *obj, QEvent *event) override;
private slots:
    void on_go_clicked();


    void on_sourcebox_currentIndexChanged(int index);

    void on_quit_clicked();

    void on_sourcebox2_currentIndexChanged(int index);


    void on_reset_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene* scene;
    SpellChecker* spellChecker;
    int radiusX, radiusY;
    int nodeSize;
    int graphSize;
    DynamicArray<QPointF> cityPositions;
    QString location, destination;
    QList<QGraphicsLineItem*> edgeLines;
    QList<QGraphicsLineItem*> pathLines;
    QList<QGraphicsEllipseItem*> cities;
    QList<QGraphicsTextItem*> labels;

    int source1, source2;
    void showGraph();
};

#endif // MAINWINDOW_H
