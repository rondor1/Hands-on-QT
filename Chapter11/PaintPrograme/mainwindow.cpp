#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPainter>
#include <QPen>
#include <QImage>
#include <QBrush>
#include <QFileDialog>
#include <QtSvg/QSvgGenerator>
#include <QDebug>
#include <QMouseEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Set the size of the image and fill background
    m_image = new QImage(this->size(), QImage::Format_RGB32);
    m_image->fill(Qt::white);

    m_brushColor = Qt::black;
    m_brushSize = 2;

    //Connect File->Save
    connect(ui->actionSave, &QAction::triggered, this, &MainWindow::saveSVG);
    //Connect File->Clear
    connect(ui->actionClear, &QAction::triggered, this, &MainWindow::clearSVG);

    //Connect brush size setting signal
    connect(ui->action2px, &QAction::triggered, this, &MainWindow::setBrushSize2px);
    connect(ui->action5px, &QAction::triggered, this, &MainWindow::setBrushSize5px);
    connect(ui->action10px, &QAction::triggered, this, &MainWindow::setBrushSize10px);

    //Connect brush color setting signal
    connect(ui->actionBlack, &QAction::triggered, this, &MainWindow::setBrushColorBlack);
    connect(ui->actionWhite, &QAction::triggered, this, &MainWindow::setBrushColorWhite);
    connect(ui->actionRed, &QAction::triggered, this, &MainWindow::setBrushColorRed);
    connect(ui->actionGreen, &QAction::triggered, this, &MainWindow::setBrushColorGreen);
    connect(ui->actionBlue, &QAction::triggered, this, &MainWindow::setBrushColorBlue);
}

MainWindow::~MainWindow()
{
    delete m_image;
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter canvasPainter(this);
    canvasPainter.drawImage(this->rect(), *m_image, m_image->rect());
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        //Drawing should start
        m_drawing = true;
        //Acquire the start position of the drawing
        m_lastAcquiredPos = event->pos();
        qDebug() << " PRessed " ;
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        //Drawing should stop
        m_drawing = false;
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if(m_drawing)
    {
        QPainter painter(m_image);
        painter.setPen(QPen(m_brushColor, m_brushSize, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
        painter.setRenderHint(QPainter::Antialiasing);

        //Draw from point to point
        painter.drawLine(m_lastAcquiredPos, event->pos());

        //Update the last saved point
        m_lastAcquiredPos = event->pos();
        this->update();
    }
}

void MainWindow::resizeEvent(QResizeEvent *event)
{

    QImage newImage(event->size(), QImage::Format_RGB32);
    newImage.fill({255, 255, 255});

    QPainter painter(&newImage);
    painter.drawImage(QPoint(0,0), newImage);
//    m_image = &newImage;

}

void MainWindow::saveSVG()
{
    qDebug() << " Save clicked ";
    auto filePath = QFileDialog::getSaveFileName(this, "Save drawn image",
                                                 "", "PNG (*.png);;JPEG (*.jpg *.jpeg);; All files (*.*)");
    if(filePath.isEmpty())
    {
        return;
    }

    m_image->save(filePath);
}

void MainWindow::clearSVG()
{
    m_image->fill(Qt::white);
    this->update();
}

void MainWindow::setBrushSize2px()
{
    m_brushSize = 2;
}

void MainWindow::setBrushSize5px()
{
    m_brushSize = 5;
}


void MainWindow::setBrushSize10px()
{
    m_brushSize = 10;
}

void MainWindow::setBrushColorBlack()
{
    m_brushColor = Qt::black;
}

void MainWindow::setBrushColorWhite()
{
    m_brushColor = Qt::white;
}

void MainWindow::setBrushColorRed()
{
    m_brushColor = Qt::red;
}

void MainWindow::setBrushColorGreen()
{
    m_brushColor = Qt::green;
}

void MainWindow::setBrushColorBlue()
{
    m_brushColor = Qt::blue;
}
