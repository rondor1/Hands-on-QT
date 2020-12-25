#include "mainwindow.h"

#include <QApplication>

#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

    QMessageBox newMessageBox;
    newMessageBox.setWindowTitle("Serious question");
    newMessageBox.setText("Am I an awesome guy?");
    newMessageBox.addButton("Seriously Yes!", QMessageBox::YesRole);
    newMessageBox.addButton("Well, no thanks!", QMessageBox::NoRole);
    //With default QT question icon
//    newMessageBox.setIcon(QMessageBox::Question);

    //With custom icon, added as a resource
    QPixmap icon(":/images/icon.png");
    newMessageBox.setIconPixmap(icon);
    return newMessageBox.exec();
//    return a.exec();
}
