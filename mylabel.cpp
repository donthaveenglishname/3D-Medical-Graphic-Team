#include "mylabel.h"
#include <QMouseEvent>
MyLabel::MyLabel(QWidget *parent):
    QLabel(parent)
{

}

void MyLabel::mouseMoveEvent(QMouseEvent *event){
    emit mouseMove(event);
}
