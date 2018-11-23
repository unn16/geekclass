#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "tamagochi.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Animal Tamagochi;
    QTimer timer;

    \
public slots:
    void feed();

public slots:
    void wash();

public slots:
    void play();

public slots:
    void feedTime();

public slots:
    void washTime();

public slots:
    void playTime();

public slots:
    void showPic();
};

#endif // MAINWINDOW_H
