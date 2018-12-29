#include "widget.h"
#include <QApplication>
#include <ctime>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
	srand(time(0));
    Widget w;
    w.show();

    return a.exec();
}
