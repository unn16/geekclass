#ifndef PLAYER_H
#define PLAYER_H
#include "ball.h"
#include <QPointF>

class Player : public Ball
{
public:
	Player(int w, int h);
	void move(int w, int h, float deltaTime, QPointF distance);
	void draw(QPainter &painter);
};

#endif // PLAYER_H
