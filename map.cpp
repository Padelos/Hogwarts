#include "map.h"

using std::cout;


Map::Map(string path) : Map(){
    
    this->path = path;
}

Map::Map(){
    this->map  = nullptr;
    this->rows = 0;
    this->cols = 0;
    this->newCols = 0;
    this->newRows = 0;
}

Map::~Map(){
    if( this->map != nullptr){
        
        int i;

        for(i=0; i < this->rows; i++){
            delete[] this->map[i];
        }

        delete[] this->map;

        this->map = nullptr;
    }
}

void Map::setMap(char **mapp){


    try
    {
        int row_numbers = this->newRows;
        int col_number = this->newCols;

        char **tmp = new char*[row_numbers];

        int i;

        for (i=0; i<row_numbers; i++){
            tmp[i] = new char[col_number+1];
            memcpy(tmp[i],mapp[i], col_number+1);
            tmp[i][col_number] = '\0';
        }

        if(this->map != nullptr){
            for(i=0; i < this->rows; i++){
                delete[] this->map[i];
            }
            delete[] this->map;

            this->map = nullptr;
        }

        this->cols = col_number;
        this->rows = row_numbers;
        this->map  = tmp;
    }
    catch(const std::bad_alloc &e)
    {
        std::cerr << "Bad allocation memory:\n";
        std::cerr << e.what() << '\n';
    }

}

char **Map::getMap(){
    return this->map;
}

void Map::setRows(int rows){
    this->rows = rows;
}


int Map::getRows(){
    return this->rows;
}


void Map::setCols(int cols){
    this->cols = cols;
}


int Map::getCols(){
    return this->cols;
}

void Map::setNewRows(int rows){
    this->newRows = rows;
}


int Map::getNewRows(){
    return this->newRows;
}


void Map::setNewCols(int cols){
    this->newCols = cols;
}


int Map::getNewCols(){
    return this->newCols;
}


void Map::setPath(string path){
    this->path = path;
}


string Map::getPath(){
    return this->path;
}


void Map::setLocations(list<GameObject*> loc){
    this->locations = loc;
}

list<GameObject*> Map::getLocations(){
    return this->locations;
}

// ======================================= 


bool compareRowCords(GameObject* obj1,GameObject* obj2){
    if (*obj1 < *obj2)
        return true;
    return false;
}

void Map::display(){
    int i;

    locations.sort(compareRowCords);

    std::list<GameObject*>::iterator it = locations.begin();

    string tmp;

    for (i=0; i < this->rows; i++){

        tmp = this->map[i];

        while( (it != locations.end()) && ( (*it)->getX() == i)){
            tmp[(*it)->getY()] = objNames[(*it)->getID()];
            it++;
        }

        std::cout << tmp << "\n";
    }

}


bool Map::loadMap(){
    ifstream inputFile(this->path);

    if(inputFile.fail()){
        return false;
    }

    try{


        if (inputFile.is_open()) {

            list<string> arr;

            string line;

            while(inputFile >> line){
                arr.push_back(line);
            }

            inputFile.close();

            

            int len_cols = arr.front().length();
            int len_rows = arr.size();

            char **tmpMap = new char*[len_rows];

            int i = 0;
            for(string str : arr){
                tmpMap[i] = new char[len_cols+1];
                strncpy(tmpMap[i], str.c_str(), len_cols);
                tmpMap[i][len_cols] = '\0';
                i++;
            }
        
            this->map = tmpMap;

            this->cols = len_cols;
            this->rows = len_rows;

            
        } else {
            throw("unable to open the file \"" + this->path + "\"");
        }
    }
    catch(const std::bad_alloc &e){
        std::cerr << "Allocation error while loading map from file";
    }

    return true;
}

Map& Map::operator+=(GameObject &g){
    this->locations.push_back(&g);
    return *this;
}


bool Map::setCordsOf(GameObject *o, Cords &cord){

    if( cord.getX() < 0 ||
        cord.getX() > this->rows ||
        cord.getY() < 0 ||
        cord.getY() > this->cols){
            return false;
        }
    
    if (map[cord.getX()][cord.getY()] == '*'){
        // throw std::invalid_argument("It's a WALL!");
        return false;
    }

    
    for(GameObject *tmp : locations){
        if(( tmp->getID() != (gameObj) G) && (*tmp == cord) && // if not GEM and not the same player
             tmp->getID() != o->getID()){
            // throw std::invalid_argument("There is an other player");
            return false;
        }
    }

    // we don't need to check if there is other player, because if there is
    // it will throw and error and won't change the values

    o->setX(cord.getX());
    o->setY(cord.getY());

    return true;

}