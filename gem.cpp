#include "gem.h"


Gem::Gem() : id(G), GameObject()
{
}

gameObj Gem::getID(){
    return this->id;
}

int Gem::getRounds()
{
    return this->rounds;
}

void Gem::setRounds(int rounds)
{
    this->rounds = rounds;
}

Gem &Gem::operator-=(const int num)
{
    this->rounds -= num;
    return *this;
}
