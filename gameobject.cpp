#include "gameobject.h"

char objNames[3] = {'P','M','G'};

GameObject::GameObject(Cords cords) : Cords(cords)
{
    
}

GameObject& GameObject::operator=(Cords &c){
    *this = c;
    return *this;
}