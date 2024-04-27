#ifndef GAMEOBJECT
#define GAMEOBJECT

#include "cords.h"



enum gameObj {P,M,G}; // P=potter M=malfoy G=gem

class GameObject : public Cords {

public:
    GameObject(Cords = {0,0});

    virtual gameObj getID() = 0;
    GameObject& operator=(Cords &);
    
};


#endif /* GAMEOBJECT */