#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QtSvg/QSvgGenerator>
#include <QFileDialog>

#include <QDebug>

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
    Q_UNUSED(event);

    paintAll();
}

void MainWindow::paintAll(QSvgGenerator *generator)
{
    QPainter painter;

    //Start all painting activity
    if(generator)
    {
        painter.begin(generator);
    }
    else
    {
        painter.begin(this);
    }

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


void MainWindow::on_actionSave_as_SVG_triggered()
{
    QString filePath = QFileDialog::getSaveFileName(this, "Save SVG", "", "SVG files (*.svg)");

    if(filePath.isEmpty())
    {
        return;
    }

    qDebug() << filePath;

    //Create SVG generator and add all of the needed
    //information for SVG file
    QSvgGenerator svgGenerator;
    svgGenerator.setFileName(filePath);
    svgGenerator.setSize(QSize(this->width(), this->height()));
    svgGenerator.setViewBox(QRect(0,0, this->width(), this->height()));
    svgGenerator.setTitle("Svg example");
    svgGenerator.setDescription("This is a SVG example file");
    paintAll(&svgGenerator);
}
