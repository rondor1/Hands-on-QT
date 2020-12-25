#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPixmap>
#include <QFileDialog>
#include <QPainter>
#include<QDebug>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->browseButton, &QAbstractButton::clicked, this, &MainWindow::browseClicked);
    connect(ui->saveButton, &QAbstractButton::clicked, this, &MainWindow::saveClicked);
    connect(ui->scaleSlider, &QAbstractSlider::valueChanged, this, &MainWindow::scaleValueChanged);
    connect(ui->horizontalSlider, &QAbstractSlider::valueChanged, this, &MainWindow::horizontalValueChanged);
    connect(ui->verticalSlider, &QAbstractSlider::valueChanged, this, &MainWindow::verticalValueChanged);
}

void MainWindow::browseClicked()
{
    //Open a file dialog and make searching for image availalbe
    QString filename = QFileDialog::getOpenFileName(this, tr("Open image"), // Name of a window
                                                    QDir::currentPath(), // Start path for a window
                                                    tr("Image Files (*.jpg *.jpeg)") //Filter
                                                    );

    //Handle a closed dialog
    if(!filename.isEmpty())
    {
        QPixmap* newPix = new QPixmap(filename);

        if(!newPix->isNull())
        {
            if(newPix->width() < 150 || newPix->height() < 150)
            {
                QMessageBox::warning(this, tr("Invalid size"),
                                     tr("Please select image larger than 150x150"));
                return;
            }

            pix = newPix;
            imageSize = pix->size();
            drawSize = pix->size();
            canDraw = true;
        }
    }
    else
    {
        canDraw = false;
        QMessageBox::warning(this, tr("Invalid file"), tr("Selected file invalid or corrupted"));
    }
}

void MainWindow::saveClicked()
{
    if(canDraw)
    {
        if(!pix->isNull())
        {
            paintImage(QCoreApplication::applicationDirPath() + "/image.jpg", 0,0);
        }
    }
}

void MainWindow::scaleValueChanged(int value)
{
    drawSize = imageSize * value / 100;
    update();
}

void MainWindow::horizontalValueChanged(int value)
{
    drawPos.setX(value*drawSize.width() / 100 * 0.5);
    update();
}

void MainWindow::verticalValueChanged(int value)
{
    drawPos.setY(value*drawSize.height() / 100 * 0.5);
    update();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    if(canDraw)
    {
        //Start drawing image at the position of Label which should hold it
        paintImage("", ui->productImage->x(), ui->productImage->y());
    }
}

void MainWindow::paintImage(QString filename, int xPos, int yPos)
{
    QPainter painter;
    QImage saveImage(150, 150, QImage::Format_RGB16);

    if(!filename.isEmpty())
    {
        painter.begin(&saveImage);
    }
    else
    {
        painter.begin(this);
    }

    if(!pix->isNull())
    {
        painter.setClipRect(xPos, yPos, 150, 150);
        painter.fillRect(QRect(xPos, yPos, 150, 150), Qt::SolidPattern);
        painter.drawPixmap(xPos-drawPos.x(), yPos-drawPos.y(), drawSize.width(), drawSize.height(),
                           *pix);
    }

    painter.end();

    if(filename != "")
    {
        saveImage.save(filename);
        QMessageBox::information(this, "Success", "Image has been successfully saved!");
    }
}

