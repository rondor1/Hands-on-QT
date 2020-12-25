#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include <QGraphicsTextItem>
#include <QPen>
#include <QBrush>

#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    QBrush greenBrush(Qt::green);
    QBrush blueBrush(Qt::blue);
    QPen pen(Qt::black);
    pen.setWidth(2);

    connect(scene, &QGraphicsScene::selectionChanged, this, &MainWindow::selectionChanged);

    auto newRect = scene->addRect(80, 0, 80, 80, pen, greenBrush);
    //Make item able to move and to be selected
    newRect->setFlag(QGraphicsItem::ItemIsMovable);
    newRect->setFlag(QGraphicsItem::ItemIsSelectable);

    auto newEllipse = scene->addEllipse(320, 300, 80, 80, pen, blueBrush);
    //Make item able to move and to be selected
    newEllipse->setFlag(QGraphicsItem::ItemIsMovable);
    newEllipse->setFlag(QGraphicsItem::ItemIsSelectable);

    auto newText = scene->addText("Hello world",QFont("Times New Roman", 32));
    //Make item able to move and to be selected
    newText->setFlag(QGraphicsItem::ItemIsMovable);
    newText->setFlag(QGraphicsItem::ItemIsSelectable);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::selectionChanged()
{
    qDebug() << "Selection has changed ";
}


