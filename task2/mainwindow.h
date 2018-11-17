#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    int n = 10;
    QTimer timer;

public slots:
    void ShadowFight();

public slots:
    void ShadowFightTime();


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
