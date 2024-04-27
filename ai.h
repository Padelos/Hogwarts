#ifndef AI
#define AI

#include "player.h"
#include "gem.h"
#include "gameobject.h"
#include "map.h"
#include "cords.h"



class PlayerAI : public Player
{
    Map *map;
    Cords goal;
    Cords moves[5];
    int move;


public:
    PlayerAI(Map * = nullptr);
    void findClosestCell();
    Cords returnMove();
    bool isValid(Cords);
    bool isUnBlocked(Cords );
    int calculateMD(Cords src);

    void setMap(Map *);
    int getMove();
};

#endif /* AI */