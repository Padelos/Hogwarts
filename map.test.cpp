#include "map.h"
#include <iostream>
#include <list>
#include <utility>
#include "player.h"
#include "gem.h"
#include "cords.h"

using namespace std;

int main(int argc, char** argv){

    Map m(argv[1]);

    list<GameObject*> myArr;

    GameObject *c;

    Player p1(M);
    c = &p1;
    
    p1.setX(8);
    p1.setY(1);

    Player p2(P);
    p2.setX(1);
    p2.setY(1);

    Gem g;
    
    g.setX(8);
    g.setY(18);

    myArr.push_back(&p1);
    myArr.push_back(&p2);
    myArr.push_back(&g);

    m.setLocations(myArr);


    m.loadMap();
    m.display();

    list<GameObject*> arr = m.getLocations();

    for(GameObject * tmp : arr){    
        cout << tmp->getID() << ": (" << tmp->getX() << "," << tmp->getY() << ")\n";
    }

    return 0;
}