#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "Dynamic_Array.h"
#include "spellchecker.h"
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

    // void on_sourcebox_2_currentIndexChanged(int index);

    void on_sourcebox_currentIndexChanged(int index);

    void on_quit_clicked();

    void on_sourcebox2_currentIndexChanged(int index);

    // void on_destinationbox_currentIndexChanged(int index);

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
    QList<QGraphicsEllipseItem*> cities;

    int source1, source2;
    void showGraph();
};

#endif // MAINWINDOW_H
