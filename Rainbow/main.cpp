#include "rainbow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Rainbow w;
    w.show();

    return a.exec();
}
