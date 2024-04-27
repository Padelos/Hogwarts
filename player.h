#ifndef PLAYER
#define PLAYER

#include "gameobject.h"

class Player : public GameObject{
    gameObj id;

public:
    Player(gameObj = P);
    gameObj getID();
};


#endif /* PLAYER */