#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked(bool)), this, SLOT(frases()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::frases(){
    QString fras[6];
    fras[0] = "England is a capital of Great Britatin";
    fras[1] = "Make Amrica Great Again";
    fras[2] = "bee isn't a dog";
    fras[3] = "dog isn't a bee";
    fras[4] = "Lil Rosty isn't a St. Roct BB";
    fras[5] = "Lil peep like a Lil Pump but pimp isn't a pump";
    int i = rand()%5 + 1;
    ui->label->setText(fras[i]);
}
