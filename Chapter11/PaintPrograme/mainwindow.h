#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QImage;
class QBrush;


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

    void mousePressEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
//    void resizeEvent()

private slots:
    //SVG manipulation
    void saveSVG();
    void clearSVG();

    //Brush size
    void setBrushSize2px();
    void setBrushSize5px();
    void setBrushSize10px();

    //Brush color
    void setBrushColorBlack();
    void setBrushColorWhite();
    void setBrushColorRed();
    void setBrushColorGreen();
    void setBrushColorBlue();
private:
    Ui::MainWindow *ui;
    QImage* m_image;
    QColor m_brushColor = Qt::black;
    int m_brushSize = 2;
    bool m_drawing = false;
    QPoint m_lastAcquiredPos = {0,0};
};
#endif // MAINWINDOW_H

