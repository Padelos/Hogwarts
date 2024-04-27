#ifndef GAMEENGINE
#define GAMEENGINE

#include <iostream>
#include <cstdlib>
#include "map.h"
#include "gem.h"
#include "player.h"
#include "cords.h"
#include "ai.h"
#include <ncurses.h>

#define KEY_SPACE 32
#define KEY_ESC 27

class GameEngine
{
    Player   p;
    PlayerAI ai;
    Gem      gem;
    Map      map;
public:
    GameEngine( );
    void initScreen();
    void displayScreen();
    void run(char *p);
    GameObject *gemFound();
    void setGemRounds();
    void initPositions();
    void randomPosition(GameObject *);
};

#endif /* GAMEENGINE */