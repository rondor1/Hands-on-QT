#include "mainwindow.h"
#include "ui_mainwindow.h"


#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include <QGraphicsTextItem>
#include <QPen>
#include <QBrush>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene  = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    QBrush greenBrush(Qt::green);
    QBrush blueBrush(Qt::blue);
    QPen pen(Qt::black);
    pen.setWidth(2);

    QGraphicsRectItem* rect = scene->addRect(80,0,80,80, pen, greenBrush);
    auto ellipse = scene->addEllipse(320, 330, 100, 50, pen, blueBrush);
    auto text = scene->addText("Hello world", QFont("Times", 30));
}

MainWindow::~MainWindow()
{
    delete ui;
}

