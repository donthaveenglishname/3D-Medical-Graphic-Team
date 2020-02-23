#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;
    QPixmap pix1;//1号
    QPixmap pix2;//2号
    QPixmap pix3;//3号区
    int cnt = 1;
    int maxCnt = 3;
    int minCnt = 1;
    void setPosZero(QLabel*label);
protected:
    void wheelEvent(QWheelEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);
private slots:
    void displayPos(QMouseEvent *event);
    void displayPos2(QMouseEvent *event);
    void displayPos3(QMouseEvent *event);
};

#endif // WIDGET_H
