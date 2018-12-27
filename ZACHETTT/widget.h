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
    bool started = false;


private:
    Ui::Widget *ui;

protected:
    void paintEvent(QPaintEvent * e);
    void mousePressEvent(QMouseEvent *e);

protected slots:
    void startgame();
    void close();

public slots:
    void crate();
};

#endif // WIDGET_H
