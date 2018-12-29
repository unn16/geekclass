#include "player.h"

Player::Player(int w, int h) : Ball(w, h)
{
	radius = 16;
}

void Player::move(int w, int h, float deltaTime, QPointF distance)
{
	if (position.x() < 0)
	{
		position.setX(0);
	}
	if (position.y() < 0)
	{
		position.setY(0);
	}
	if (position.x() > w-radius*2)
	{
		position.setX(w-radius*2);
	}
	if (position.y() > h-radius*2)
	{
		position.setY(h-radius*2);
	}
	velocity.setY(distance.y());
	velocity.setX(distance.x());



	position.setX(position.x()+velocity.x()*deltaTime);
	position.setY(position.y()+velocity.y()*deltaTime);
}

void Player::draw(QPainter &painter)
{
    painter.drawPixmap(position.x(), position.y(), QPixmap(":/files/files/android.jpg").width()/12, 2*radius,
                      QPixmap(":/files/files/android.jpg"));
}
