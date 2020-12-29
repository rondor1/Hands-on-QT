#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QSvgGenerator;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void paintEvent(QPaintEvent* event);

private:
    void paintAll(QSvgGenerator* generator = nullptr);

private slots:
    void on_actionSave_as_SVG_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
