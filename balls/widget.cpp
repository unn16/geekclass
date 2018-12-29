#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
	this->health = 10;
    ui->setupUi(this);
	player = new Player(this->width(), this->height());
	ui->livesLcd->hide();
	this->start = false;
	timer.start();
	playerDPS.start();
	framerate.setInterval(1000/60);
	framerate.start();
	connect(&framerate, SIGNAL(timeout()), this, SLOT(update()));


}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *e)
{
	if (!start) return;
	ui->livesLcd->display(health);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
	for (int i = 0; i < BALLS_AMOUNT; i++)
    {
        this->balls[i].draw(painter);
	}
	this->player->draw(painter);

}

void Widget::keyPressEvent(QKeyEvent *event)
{
	if (event->key() == Qt::Key_W)
	{
		player->move(this->width(), this->height(), deltaTime, QPointF(0, -200));
	}
	if (event->key() == Qt::Key_A)
	{
		player->move(this->width(), this->height(), deltaTime, QPointF(-200, 0));
	}
	if (event->key() == Qt::Key_S)
	{
		player->move(this->width(), this->height(), deltaTime, QPointF(0, 200));
	}
	if (event->key() == Qt::Key_D)
	{
		player->move(this->width(), this->height(), deltaTime, QPointF(200, 0));
	}
}

void Widget::move()
{

}

void Widget::update()
{

	if (!start)
		if (!start) return;
	player->move(this->width(), this->height(), deltaTime, QPointF(0, 0));
	this->deltaTime = timer.restart()/(float)1000;
	for (int i = 0; i < BALLS_AMOUNT; i++)
	{
		if (this->player->collision(balls[i]) && playerDPS.elapsed() > 500)
		{
			health--;
			if (health <= 0)
			{
				QMessageBox info;
				this->timeAlive -= time(0);
				info.setIcon(QMessageBox::Warning);
				info.setText("Вы были живы " + QString::number(-timeAlive) + " секунд!");

				while (info.exec() != QMessageBox::Ok){};
				exit(0);
			}
			playerDPS.restart();
		}
	}

	for (int i = 0; i < BALLS_AMOUNT; i++)
	{
		this->balls[i].move(this->width(), this->height(), deltaTime);
	}
	for (int i = 0; i < BALLS_AMOUNT; i++)
	{
		for (int j = 0; j < BALLS_AMOUNT; j++)
		{
			if (j == i)
			{
				continue;
			}
			if (this->balls[i].collision(this->balls[j]))
			{
				this->balls[i].reverse();
			}
		}
	}
	this->repaint();

}

void Widget::on_playBtn_clicked()
{
	ui->exitBtn->hide();
	ui->playBtn->hide();
	ui->livesLcd->show();
	this->timeAlive = time(0);
	start = true;
	for (int i = 0; i < BALLS_AMOUNT; i++)
	{
		this->balls.push_back(Ball(this->width(), this->height()));
	}
}

void Widget::on_exitBtn_clicked()
{
	exit(0);
}
