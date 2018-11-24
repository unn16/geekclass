#ifndef RAINBOW_H
#define RAINBOW_H

#include <QWidget>
#include <QPaintEvent>

namespace Ui {
class Rainbow;
}

class Rainbow : public QWidget
{
    Q_OBJECT

public:
    explicit Rainbow(QWidget *parent = nullptr);
    ~Rainbow();

private:
    Ui::Rainbow *ui;

protected:
     void paintEvent(QPaintEvent * e);
};

#endif // RAINBOW_H
