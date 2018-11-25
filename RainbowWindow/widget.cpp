#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QTimer>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(&timer, SIGNAL(timeout()), this, SLOT(repaintWindow()));
    timer.start(20);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent * e)
{
    QPainter painter(this);

    int width = this -> width();
    int height = this -> height();
    painter.setBrush(QColor::fromRgb(Widget::ChangeColorR(),Widget::ChangeColorG(),Widget::ChangeColorB()));
    painter.drawRect(0,0,width,height);
}

int Widget::ChangeColorR()
{
    if (r == 255 or r == 0) i++;
    if (i%2==1) r++;
    else r--;
    return r;
}

int Widget::ChangeColorG()
{
    if (g == 254 or g == 0) j++;
    if (j%2==1) g+= 2;
    else g-= 2;
    return g;
}

int Widget::ChangeColorB()
{
    if (b == 255 or b == 0) k++;
    if (k%2==1) b+=3;
    else b-=3;
    return b;
}

int Widget::repaintWindow()
{
    repaint();
}
