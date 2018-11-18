#ifndef TAMAGOCHI_H
#define TAMAGOCHI_H

#include <QObject>

class Animal {
private:
    QString name; //имя
    int health; //здоровье
    int happiness; //счастье
    int food; //сытость
    int last_action; // время(!) последнего действия
public:
    Animal() ;

    int feed() ;
    int feedTime();

    int play();
    int playTime();

    int wash() ;
    int washTime();


};


#endif // TAMAGOCHI_H
