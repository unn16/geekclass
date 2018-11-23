#include "tamagochi.h"

Animal::Animal()
{
            health= rand() % 50 +10;
            food = rand() % 50 +10;
            happiness = rand() % 50 +10;
            results = health + food + happiness;

}

int Animal::feed() {
    if (food <= 90) {
        food += 10;
        results += 10;
    }
    return food;
}

int Animal::feedTime() {
    food -= 1;
    results -= 1;
    return food;
}

int Animal::play() {
    if (happiness <= 90) {
        happiness += 10;
        results += 10;
        }
    return happiness;
}
int Animal::playTime() {
    happiness -= 1;
    results -= 1;
    return happiness;
}

int Animal::wash() {
    if (health <= 90) {
        health += 10;
        results += 10;
    }
    return health;
}

int Animal::washTime() {
    health -= 1;
    results -= 1;
    return health;
}

int Animal::showPic(){
    return results;
}
