#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(&timer, SIGNAL(timeout()), this, SLOT(ShadowFight()));
    timer.start(1000);
    connect(ui->pushButton, SIGNAL(clicked(bool)), this, SLOT(ShadowFightTime()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ShadowFight(){
    n--;
    this->ui->progressBar->setValue(n);

    if (n<0){
        close();
    }

    if (n > 100){
        close();
    }

}

void MainWindow::ShadowFightTime()
{
    n++;
    this->ui->progressBar->setValue(n);
}

