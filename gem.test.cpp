#include <iostream>
#include "gem.h"

using namespace std;

int main(){

    Gem g;

    cout << "Gem ID: " << g.getID() << endl;
    cout << "(x,y) -> (" << g.getX() << "," << g.getY() << ")\n";
    
    g.setX(5);
    g.setY(8);
    cout << "(x,y) -> (" << g.getX() << "," << g.getY() << ")\n";  

    return 0;
}