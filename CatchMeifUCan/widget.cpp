#include "widget.h"
#include "ui_widget.h"
#include<QPainter>
#include <QTimer>
#include <QtDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(&timer,SIGNAL(timeout()),this, SLOT(crate()));
    timer.start(3000);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    qDebug() << "repainting";
    int width = this -> width();
    int height = this -> height();

    x = rand()% width;
    y = rand()% height;

    painter.setPen(Qt::red);
    painter.setBrush(Qt::blue);
    painter.drawEllipse(QPoint(x,y),20,20);
}

void Widget::mousePressEvent(QMouseEvent *e)
{
    int xm =e->x();
    int ym =e -> y();
    qDebug() << xm << " " << ym << " " << x << " " << y << " ";
    if (((xm - x)* (xm - x)+((ym - y)*(ym - y))) < 400) Widget::scoreup();
      repaint();

}

void Widget::crate()
{
    repaint();
}

void Widget::scoreup()
{qDebug() << "pressed";

    score+=10;
    ui->lcdNumber->display(score);
}
