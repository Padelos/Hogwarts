#include <iostream>
#include "player.h"

using namespace std;

int main(){

    Player p1(P);
    Player p2(M);

    cout << "p1 ID: " << p1.getID() << endl;
    cout << "(x,y) -> (" << p1.getX() << "," << p1.getY() << ")\n";
    
    p2.setX(5);
    p2.setY(8);
    cout << "p2 ID: " << p2.getID() << endl;
    cout << "(x,y) -> (" << p2.getX() << "," << p2.getY() << ")\n";  


    return 0;
}