#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include <QTimer>
#include <QElapsedTimer>
#include <QVector>
#include <QKeyEvent>
#include <QMessageBox>
#include <ctime>
#include "ball.h"
#include "player.h"
#define BALLS_AMOUNT 20

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
    QTimer moveInterval;
	QTimer framerate;
	QElapsedTimer timer;
	QElapsedTimer playerDPS;
	float deltaTime;
    QVector<Ball> balls;
	Player* player;
	bool start;
	int timeAlive;

private:
    Ui::Widget *ui;
		int health;
protected:
    void paintEvent(QPaintEvent* e);
	void keyPressEvent(QKeyEvent *event);

private slots:
    void move();
	void update();
	void on_playBtn_clicked();
	void on_exitBtn_clicked();
};

#endif // WIDGET_H
