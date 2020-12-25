#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QPaintEvent;
class QPainter;
class QPixmap;

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
    void paintImage(QString filename, int xPos, int yPos);

private slots:
    void browseClicked();
    void saveClicked();
    void scaleValueChanged(int value);
    void horizontalValueChanged(int value);
    void verticalValueChanged(int value);
private:
    Ui::MainWindow *ui;
    bool canDraw;
    QPixmap* pix;
    QSize imageSize;
    QSize drawSize;
    QPoint drawPos;
};
#endif // MAINWINDOW_H
