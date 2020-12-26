#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>

class QGraphicsScene;
class QKeyEvent;
class profileLine;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void keyReleaseEvent(QKeyEvent* event);
    void updateLines();

private slots:
    void selectionChanged();
    void AddNewProfile();

private:
    Ui::MainWindow *ui;
    QGraphicsScene* scene;
    QList<profileLine*> lines;
};
#endif // MAINWINDOW_H
