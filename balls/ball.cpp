#include "ball.h"

Ball::Ball()
{

}

Ball::Ball(int w, int h)
{
    init(w, h);
}

void Ball::init(int w, int h)
{
    this->position.setX(rand()%w);
    this->position.setY(rand()%h);

	this->radius = 20+(rand()%30);

    this->color = QColor(rand()%256, rand()%256, rand()%256);

	velocity.setX(60);
	velocity.setY(60);

	if (rand()%2 == 1) velocity.setX(-60);
	if (rand()%2 == 1) velocity.setY(-60);
}

void Ball::move(int w, int h, float deltaTime)
{

	if (position.x() < radius)
    {
		velocity.setX(60);
    }
	if (position.y() < radius)
    {
		velocity.setY(60);
    }
	if (position.x() > w-radius)
    {
		velocity.setX(-60);
    }
	if (position.y() > h-radius)
    {
		velocity.setY(-60);
    }
	position.setX(position.x()+velocity.x()*deltaTime);
	position.setY(position.y()+velocity.y()*deltaTime);


}

int Ball::getRadius()
{
	return radius;
}

QPointF Ball::getPosition()
{
	return position;
}

bool Ball::collision(Ball &ball)
{
	float distance =
				pow(abs(this->position.x()-ball.getPosition().x()), 2)+
				pow(abs(this->position.y()-ball.getPosition().y()), 2);
	return pow(radius+ball.getRadius(), 2) >= distance;
}

void Ball::draw(QPainter &painter)
{
    painter.drawPixmap(position.x()-radius, position.y()-radius, 2*radius, 2*radius,				  QPixmap(":/files/files/ios.jpg"));
}

void Ball::reverse()
{
	this->velocity.setX(-velocity.x());
	this->velocity.setY(-velocity.y());
}
