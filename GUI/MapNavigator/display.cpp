#include "display.h"
#include "ui_display.h"
#include "graphitem.h"
#include "welcomepage.h"
#include <QtMath>
#include <QGraphicsEllipseItem>

display::display(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::display)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    ui->graphicsView->setRenderHint(QPainter::Antialiasing);

    showGraph();
}

display::~display()
{
    delete ui;
}

void display::showGraph() {
    scene->clear();
    cityPositions.clear();

    radius = 200;
    nodeSize = 30;
    // graphSize = graph.getSize();



    for (int i = 0; i < graph.getSize(); i++) {
        qreal angle = 2.0 * M_PI * (i/static_cast<qreal>(graph.getSize()));
        qreal x = radius * qCos(angle);
        qreal y = radius * qSin(angle);

        QRectF rect((x - nodeSize / 2), (y - nodeSize / 2), nodeSize, nodeSize);
        QColor color(128, 162, 146);
        QBrush brush(color);
        QGraphicsEllipseItem* city = scene->addEllipse(rect, QPen(Qt::white), brush);
        QPointF center = city->sceneBoundingRect().center();

        cityPositions.push_back(center);

        QGraphicsTextItem* name = scene->addText(graph.getCityName(i));
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

            scene->addLine(QLineF(p1, p2), QPen(Qt::darkCyan));
        }
    }




}

void display::on_back_clicked()
{

    setAttribute(Qt::WA_DeleteOnClose);
    this->close();
    welcomePage* welcome = new welcomePage(nullptr);
    welcome->show();
}

