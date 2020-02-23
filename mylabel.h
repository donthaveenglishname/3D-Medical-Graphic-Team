#ifndef MYLABEL_H
#define MYLABEL_H
#include <QWidget>
#include <QLabel>

class MyLabel : public QLabel
{
    Q_OBJECT
public:
    explicit MyLabel(QWidget *parent = 0);
signals:
   void mouseMove(QMouseEvent *event);
protected:
  void  mouseMoveEvent(QMouseEvent *event);
};

#endif // MYLABEL_H
