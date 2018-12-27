#include "widget.h"
#include "ui_widget.h"
#include<QPainter>
#include <QTimer>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    connect(ui->PlayButton,SIGNAL(clicked()),this,SLOT(StartGame()));
    connect(ui->ExitButton,SIGNAL(clicked()),this,SLOT(ExitGame()));
    ui->setupUi(this);
    timer.start(3000);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *e)
{
    if (started == true){
        QPainter painter(this);
        int width = this -> width();
        int height = this -> height();

        x = rand()% width;
        y = rand()% height;

        painter.setPen(Qt::red);
        painter.setBrush(Qt::blue);
        painter.drawEllipse(QPoint(x,y),20,20);

    }
}

void Widget::mousePressEvent(QMouseEvent *e)
{
    if (started == true){
        int xm =e->x();
        int ym =e -> y();
        if (((xm - x)* (xm - x)+((ym - y)*(ym - y))) < 400) repaint();
    }
}

void Widget::startgame()
{
    ui-> PlayButton->hide();
    ui-> ExitButton-> hide();
    started = true;

}

void Widget::close()
{
    this-> close();
}

void Widget::crate()
{
    repaint();
}

