#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter;

    //Start all painting activity
    painter.begin(this);

    //Draw A line
    painter.drawLine(QPoint(50, 60), QPoint(100,100));

    //Draw a rectangle
    painter.setBrush(Qt::BDiagPattern);
    painter.drawRect(QRect(40,120,80,30));

    //Draw an ellipse
    QPen ellipsePen;
    ellipsePen.setColor(Qt::yellow);
    ellipsePen.setStyle(Qt::DashDotDotLine);
    painter.setPen(ellipsePen);
    painter.drawEllipse(QPoint(80,200), 50,20);

    //Draw a rectangle
    QPainterPath rectPath;
    rectPath.addRect(QRect(150, 20,100, 50));
    painter.setPen(QPen(Qt::red, 1, Qt::DashDotDotLine, Qt::FlatCap, Qt::MiterJoin));
    painter.setBrush(Qt::yellow);
    painter.drawPath(rectPath);

    //Draw a ellipse
    QPainterPath ellipsePath;
    ellipsePath.addEllipse(QPoint(200, 120), 50, 20);
    painter.setPen(QPen(QColor(79, 106, 25), 5, Qt::SolidLine, Qt::FlatCap, Qt::MiterJoin));
    painter.setBrush(QColor(122, 163, 39));
    painter.drawPath(ellipsePath);

    //Draw a text
    painter.setFont(QFont("Times", 14, QFont::Bold));
    painter.drawText(QPoint(50, 60), "Testing");

    //End all painting activity
    painter.end();

}
