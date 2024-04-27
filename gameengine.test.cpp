#include "gameengine.h"
#include <iostream>

using namespace std;

int main(int argc, char** argv){

    
    GameEngine engine;

    engine.run(argv[1]);
    
    

    return 0;
}