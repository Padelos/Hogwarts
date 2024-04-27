#ifndef MAP
#define MAP


#include <iostream>
#include <cstring>
#include <fstream>
#include <list>
#include <utility>
#include <algorithm>
#include "gameobject.h"

using std::string;
using std::ifstream;
using std::list;
using std::pair;

extern char objNames[];


class Map{
        string path;
        char** map;
        int    rows;
        int    cols;
        int    newRows;
        int    newCols;

        list<GameObject*> locations; // cords and ID
    protected:
        void   setMap(char**);
    public:
        Map (string path);
        Map ();
        ~Map();

        char** getMap();
        void   setRows(int);
        int    getRows();
        void   setCols(int);
        int    getCols();
        void   setNewRows(int);
        int    getNewRows();
        void   setNewCols(int);
        int    getNewCols();
        void   setPath(string);
        string getPath();

        void setLocations(list<GameObject*> );
        list<GameObject*> getLocations();

        void   display();

        Map& operator+=(GameObject &);

        bool setCordsOf(GameObject *, Cords &);


        bool loadMap();
};

#endif /* MAP*/