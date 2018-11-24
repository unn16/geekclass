#include "rainbow.h"
#include "ui_rainbow.h"
#include <QPainter>

Rainbow::Rainbow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Rainbow)
{
    ui->setupUi(this);
}

Rainbow::~Rainbow()
{
    delete ui;
}

void Rainbow::paintEvent(QPaintEvent *e)
{
    QPainter painter(this) ;

    int width = this -> width();
    int height = this -> height();

    QColor colors[] = {Qt::red, QColor::fromRgb(255, 165, 0), QColor::fromRgb(255,255,0), Qt::green, QColor::fromRgb(0, 255, 255), Qt::blue, QColor::fromRgb(102, 0, 204)};

    for (int i = 0; i < 7; i++) {
        painter.setPen(colors[i]);
        painter.setBrush(colors[i]);
        painter.drawEllipse(QPoint(width/2, height), width/2 - width/14*i,height - height/7*i) ;
    }
}

