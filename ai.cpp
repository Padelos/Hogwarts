#include "ai.h"

PlayerAI::PlayerAI(Map *map) : Player(M), goal({-1,-1})
{
    moves[0] = {-1,0}; // north
    moves[1] = {1,0}; // south
    moves[2] = {0,1}; // east
    moves[3] = {0,-1}; // west
    moves[4] = {0,0}; // no available moves
    this->map = map;
}

void PlayerAI::findClosestCell()
{
    GameObject *target = nullptr;
    
    for(GameObject *tmp : this->map->getLocations() ){
        if (tmp->getID() == G){
            target = tmp;
        }
    }

    if(target == nullptr){
        throw("There's no Gem!!!");
    }


    Cords src = *this;
    goal = *target;

    int i;


    int tmpRow;
    int tmpCol;
    int tmp = map->getCols() * map->getRows();
    int res = tmp,resIndex = 4;

    for(i = 0; i < 4; i++){
        tmpRow = src.getX() + moves[i].getX();
        tmpCol = src.getY() + moves[i].getY();

        if ( isValid({tmpRow,tmpCol}) && isUnBlocked({tmpRow,tmpCol}) ){

            tmp = calculateMD({tmpRow,tmpCol});
            if(tmp < res){
                res = tmp;
                resIndex = i;
            }
        }
    }

    move = resIndex;

}

Cords PlayerAI::returnMove(){
    return moves[move];
}


bool PlayerAI::isValid(Cords cord)
{
    // Returns true if row number and column number
    // is in range
    return (cord.getX() >= 0) &&
        (cord.getX() < map->getRows() ) &&
        (cord.getY() >= 0) &&
        (cord.getY() < map->getCols() );
}

bool PlayerAI::isUnBlocked(Cords cord)
{
    // Returns true if the cell is not blocked else false
    if ((map->getMap()[cord.getX()][cord.getY()]) == '*')
        return false;

    for(GameObject *tmp : map->getLocations()){
        if( !(tmp->getID() == this->getID()) &&
            !(tmp->getID() == G) &&
            ( *tmp == cord)){
                return false;
            }
    }
    
    
    return true;
}


int PlayerAI::calculateMD(Cords src)
{
    int i = (src.getX() - goal.getX());
    int j = (src.getY() - goal.getY());

    if (i < 0)
        i *= -1;
    
    if (j < 0)
        j *= -1;

    return (i+j);
}

void PlayerAI::setMap(Map *map)
{
    this->map = map;
}

int PlayerAI::getMove()
{
    return this->move;
}
