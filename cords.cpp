#include "cords.h"

Cords::Cords(int x, int y){
    this->x = x;
    this->y = y;
}

Cords::Cords(const Cords &c){
    this->x = c.x;
    this->y = c.y;
}

Cords &Cords::operator=(const Cords &c){
    this->x = c.x;
    this->y = c.y;

    return *this;
}

int Cords::getX(){
    return this->x;
}

int Cords::getY(){
    return this->y;
}

void Cords::setX(int x){
    this->x = x;
}

void Cords::setY(int y){
    this->y = y;
}
