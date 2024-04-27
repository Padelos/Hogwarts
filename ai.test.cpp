#include "ai.h"
#include <iostream>
#include "map.h"
#include "gem.h"

using namespace std;

int main(){

    Map map("map10-20.txt");
    map.loadMap();

    PlayerAI ai(&map);
    ai.setX(4);
    ai.setY(5);

    Gem g;
    g.setX(4);
    g.setY(6);

    map+=ai;
    map+=g;

    ai.findClosestCell();
    Cords mo = ai.returnMove();
    cout << mo.getX() << "," << mo.getY() << endl;

    map.display();

    return 0;
}