#ifndef GEM
#define GEM

#include "gameobject.h"
#include "cords.h"


class Gem : public GameObject{

    gameObj id;
    int rounds;

public:
    Gem();
    gameObj getID();
    
    int getRounds();
    void setRounds(int);
    Gem &operator-=(const int);

};



#endif /* GEM */