#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "profilebox.h"
#include "profileline.h"

#include <QGraphicsScene>
#include <QInputDialog>

#include <QKeyEvent>

#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    connect(scene, &QGraphicsScene::selectionChanged, this, &MainWindow::selectionChanged);
    connect(ui->addNewItem, &QAbstractButton::clicked, this, &MainWindow::AddNewProfile);

    profileBox* newBox = new profileBox();
    newBox->init("John Doe", this, scene);

}

void MainWindow::selectionChanged()
{

}

void MainWindow::AddNewProfile()
{
    bool ok;
    QString newName = QInputDialog::getText(this, tr("Employee name"),
                                            tr("Please insert the name of a new employee:"),
                                            QLineEdit::Normal, //Type of line edit
                                            "John Doe", // Name format as hint
                                            &ok //Pointer to the bool holding return value status
                                            );
    if(ok && !newName.isEmpty())
    {
        auto newProfile = new profileBox();
        newProfile->init(newName, this, scene);

        if(scene->selectedItems().size() > 0)
        {
            profileLine* line = new profileLine();
            line->initLine(newProfile, scene->selectedItems().at(0));
            scene->addItem(line);

            lines.push_back(line);
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    qDebug() << "Key released " << event->text();

    if(event->key() == Qt::Key_Delete)
    {
        qDebug() << " Delete key pressed ";

        QGraphicsItem* selected = scene->selectedItems().at(0);
        scene->removeItem(selected);

        for(int i =0; i < lines.size(); ++i)
        {
            profileLine* line = lines.at(i);
            if(line->startBox == selected || line->endBox == selected)
            {
                lines.removeAt(i);
                scene->removeItem(line);
                delete line;
            }
        }
        delete selected;
    }
}

void MainWindow::updateLines()
{
    if(lines.size() > 0)
    {
        for(auto it : lines)
        {
            it->updateLine();
        }
    }
}

