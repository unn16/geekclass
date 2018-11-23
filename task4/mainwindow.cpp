#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton_Feed, SIGNAL(clicked(bool)), this, SLOT(feed()));
    connect(&timer, SIGNAL(timeout()), this, SLOT(feedTime()));
    connect(ui->pushButton_Wash, SIGNAL(clicked(bool)), this, SLOT(wash()));
    connect(&timer, SIGNAL(timeout()), this, SLOT(washTime()));
    connect(ui->pushButton_Play, SIGNAL(clicked(bool)), this, SLOT(play()));
    connect(&timer, SIGNAL(timeout()), this, SLOT(playTime()));
    timer.start(300);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::feed()
{
    int food = Tamagochi.feed();
    this->ui->progressBar_Food->setValue(food);
    if (food == 0 ) close();

}

void MainWindow::wash()
{
    int health =Tamagochi.wash();
    this->ui->progressBar_Health->setValue(health);
    if (health == 0) close();
}

void MainWindow::play()
{
     int happiness = Tamagochi.play();
     this->ui->progressBar_Happinnes->setValue(happiness);
     if (happiness == 0) close();
}

void MainWindow::feedTime()
{
    int food = Tamagochi.feedTime();
    this->ui->progressBar_Food->setValue(food);
    if (food == 0) close();
    MainWindow::showPic();
}

void MainWindow::washTime()
{
    int health =Tamagochi.washTime();
    this->ui->progressBar_Health->setValue(health);
    if (health == 0) close();
    MainWindow::showPic();
}

void MainWindow::playTime()
{
    int happiness = Tamagochi.playTime();
    this->ui->progressBar_Happinnes->setValue(happiness);
    if (happiness == 0) close();
    MainWindow::showPic();
}

void MainWindow::showPic()
{
    int results = Tamagochi.showPic();
    if (results > 200) ui->label_image->setPixmap(QPixmap(":/files/Images/IfHappy.jpg"));
    else if (results < 60) ui->label_image->setPixmap(QPixmap(":/files/Images/IfAngry.jpg"));
    else ui->label_image->setPixmap(QPixmap(":/files/Images/IfNormal.jpg"));
}

