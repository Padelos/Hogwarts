#include "gameengine.h"
#include <iostream>

using namespace std;

int main(int argc, char** argv){

    if (argc <= 1) {
        cout << "Usage: " << argv[0] << " <filename>" << endl;
        return EXIT_SUCCESS;
    }
    
    GameEngine engine;

    try
    {
        engine.run(argv[1]);
    }
    catch(const char *e)
    {
        std::cerr << e << '\n';
    }    
    

    return EXIT_SUCCESS;
}