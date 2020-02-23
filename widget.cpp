#include "widget.h"
#include "ui_widget.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QGridLayout>
#include <QPixmap>
#include <QDebug>
#include <QWheelEvent>
#include <QPainter>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
//    QGraphicsScene *qgs = new QGraphicsScene(this);
//    qgs->addWidget(ui->label);
//    qgs->addWidget(ui->label_2);
//    qgs->addWidget(ui->label_3);
//    qgs->addWidget(ui->label_4);
    pix1.load(":/img/image/1.png");
    pix2.load(":/img/image/1.png");
    pix3.load(":/img/image/1.png");


    this->showMaximized();
    QPainter painter(this);
    painter.fillRect(ui->label->geometry(),QColor(0,0,0));//先给底色黑色
    painter.fillRect(ui->label_2->geometry(),QColor(0,0,0));
    painter.fillRect(ui->label_3->geometry(),QColor(0,0,0));
    pix1 = pix1.scaled(ui->label->size());
    pix2 = pix2.scaled(ui->label_2->size());//统一大小
    pix3 = pix3.scaled(ui->label_3->size());
    ui->label->setScaledContents(true);//一号位置
    ui->label->setStyleSheet("QLabel#label{border-image:url(:/img/image/1.png)}" );
    ui->label->setPixmap(pix1);
    ui->label_2->setScaledContents(true);//二号位置
    ui->label_2->setPixmap(pix2);
    ui->label_3->setScaledContents(true);//三号
    ui->label_3->setPixmap(pix3);
    ui->label_4->setScaledContents(true);//四号位置，应该是3D图，暂时先放个图上去
    ui->label_4->setPixmap(pix1);
    connect(ui->label,&MyLabel::mouseMove,this,&Widget::displayPos);
    connect(ui->label_2,&MyLabel::mouseMove,this,&Widget::displayPos2);
    connect(ui->label_3,&MyLabel::mouseMove,this,&Widget::displayPos3);
    ui->label->setMouseTracking(true);
    ui->label_2->setMouseTracking(true);
    ui->label_3->setMouseTracking(true);
    setMouseTracking(true);

    //给坐标特殊字体颜色
    QPalette qpe;
    qpe.setColor(QPalette::WindowText,Qt::red);
    ui->pixPos1Val->setPalette(qpe);
    ui->pixPos2Val->setPalette(qpe);
    ui->pixPos3Val->setPalette(qpe);
    ui->CT1Val->setPalette(qpe);
    ui->CT2Val->setPalette(qpe);
    ui->CT3Val->setPalette(qpe);
}

Widget::~Widget()
{
    delete ui;
}
void Widget::wheelEvent(QWheelEvent *event){
    qDebug()<<"now cnt:"<<cnt;
    if(event->delta() > 0){
        int degree = event->delta()/8/15;
        cnt-=degree;
        if(cnt < minCnt){
            cnt = 3;
        }
        QString path = QString(":/img/image/") + QString::number(cnt) +QString(".png");
        //1号区图片
        pix1.load(path);
        pix1 = pix1.scaled(ui->label->size());
        //2号区图片，后面加载的图片路径需要专门设置
        pix2.load(path);
        pix2 = pix2.scaled(ui->label_2->size());
        //3号区图片，后面加载的图片路径需要专门设置
        pix3.load(path);
        pix3 = pix3.scaled(ui->label_3->size());
        ui->label->setPixmap(pix1);

        //二号位置
        ui->label_2->setPixmap(pix2);
        //3号
        ui->label_3->setPixmap(pix3);


    }else if(event->delta()<0){
        int degree = event->delta()/8/15;
        cnt-=degree;
        if(cnt > maxCnt){
            cnt = 1;
        }
        QString path = QString(":/img/image/") + QString::number(cnt) +QString(".png");
        //1号区图片
        pix1.load(path);
        pix1 = pix1.scaled(ui->label->size());
        //2号区图片，后面加载的图片路径需要专门设置
        pix2.load(path);
        pix2 = pix2.scaled(ui->label_2->size());
        //3号区图片，后面加载的图片路径需要专门设置
        pix3.load(path);
        pix3 = pix3.scaled(ui->label_3->size());
        ui->label->setPixmap(pix1);
        ui->label_2->setPixmap(pix2);
        ui->label_3->setPixmap(pix3);
    }
}

void Widget::mouseMoveEvent(QMouseEvent *event){//绘制固定点的坐标
    setPosZero(ui->pixPos1Val);
    setPosZero(ui->pixPos2Val);
    setPosZero(ui->pixPos3Val);
}
void Widget::setPosZero(QLabel *label){
   // qDebug()<<"in";
    label->setText(QString("x:0 y:0"));
}
void Widget::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    painter.fillRect(this->rect(), QColor(150, 150, 150));
}
void Widget::displayPos(QMouseEvent *event){
    //qDebug()<<event->pos();;
int x = event->x();
int y = event->y();
    QString text = QString("x:")+QString::number(x)+
            QString(" y:")+QString::number(y);
    ui->pixPos1Val->setText(text);

}
void Widget::displayPos2(QMouseEvent *event){
    int x = event->x();
    int y = event->y();
    QString text = QString("x:")+QString::number(x)+
            QString(" y:")+QString::number(y);
    ui->pixPos2Val->setText(text);
}
void Widget::displayPos3(QMouseEvent *event){
    int x = event->x();
    int y = event->y();
    QString text = QString("x:")+QString::number(x)+
            QString(" y:")+QString::number(y);
    ui->pixPos3Val->setText(text);
}
