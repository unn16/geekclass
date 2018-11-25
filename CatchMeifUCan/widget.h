#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPaintEvent>
#include <QTimer>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
    QTimer timer;
    int score = 0;
    int x,y;


private:
    Ui::Widget *ui;

protected:
    void paintEvent(QPaintEvent * e);
    void mousePressEvent(QMouseEvent *e);

public slots:
    void crate();

public slots:
    void scoreup();
};

#endif // WIDGET_H
