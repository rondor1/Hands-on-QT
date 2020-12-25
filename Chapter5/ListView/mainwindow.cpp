#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QListWidgetItem>

#include <QTreeWidgetItem>

#include <QTableWidgetItem>

#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->listWidget->addItem("My custom item");


    //Adding data to list widget
    QListWidgetItem* myItem = new QListWidgetItem("My second custom item");
    myItem->setData(100, 100);
    ui->listWidget->addItem(myItem);

    qDebug() << myItem->data(100);

    //Adding data to tree widget
    QTreeWidgetItem* treeItem = new QTreeWidgetItem;
    QTreeWidgetItem* treeItem2 = new QTreeWidgetItem;
    treeItem->setText(0,"Text data");
    ui->treeWidget->addTopLevelItem(treeItem);
    treeItem2->setText(0, "New text data");
    treeItem->addChild(treeItem2);


    //Adding data to the table
    QTableWidgetItem* newTableWidgetItem = new QTableWidgetItem;
    newTableWidgetItem->setText("First added data");
    QTableWidgetItem* newTableWidgetItem2 = new QTableWidgetItem;
    newTableWidgetItem2->setText("First added data");
    ui->tableWidget->setItem(0,0, newTableWidgetItem);
    ui->tableWidget->setItem(1,1,
                             newTableWidgetItem2);

}

MainWindow::~MainWindow()
{
    delete ui;
}

