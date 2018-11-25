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
    int r = 0;
    int g = 0;
    int b = 0;
    int i = 0;
    int j = 0;
    int k = 0;

protected:
    void paintEvent(QPaintEvent * e);

public slots:
    int ChangeColorR();

public slots:
    int ChangeColorG();

public slots:
    int ChangeColorB();

public slots:
    int repaintWindow();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
