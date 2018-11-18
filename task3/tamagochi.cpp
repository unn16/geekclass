#include "tamagochi.h"

Animal::Animal()
{
            health= rand() % 50 +1;
            food = rand() % 50 +1;
            happiness = rand() % 50 +1;

}

int Animal::feed() {
    //изменить food
    //изменить last_action
    if (food <= 90) food += 10;
    return food;
}

int Animal::feedTime() {
    //изменить food
    //изменить last_action
    food -= 1;
    return food;
}

int Animal::play() {
    //изменить happiness
    //изменить last_action
    if (happiness <= 90) happiness += 10;
    return happiness;
}
int Animal::playTime() {
    //изменить happiness
    //изменить last_action
    happiness -= 1;
    return happiness;
}

int Animal::wash() {
    //изменить health
    //изменить last_action
    if (health <= 90) health += 10;
    return health;
}

int Animal::washTime() {
    //изменить health
    //изменить last_action
    health -= 1;
    return health;
}
