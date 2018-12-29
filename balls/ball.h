#ifndef BALL_H
#define BALL_H
#include <QColor>
#include <QPainter>
#include <QPointF>
#include <cmath>


class Ball
{
public:
    Ball();
    Ball(int w, int h);
    void init(int w, int h);
	void move(int w, int h, float deltaTime);
	int getRadius();
	QPointF getPosition();
	bool collision(Ball& ball);
    void draw(QPainter& painter);
	void reverse();
protected:
	QPointF velocity;
	QPointF position;
	int radius;
    QColor color;
};

#endif // BALL_H
