#include "player.h"

Player::Player(gameObj id) : GameObject(){
    this->id = id;
}

gameObj Player::getID(){
    return this->id;
}
