#ifndef CORDS
#define CORDS

class Cords {

    int x,y; // row / col position
    
public:
    Cords(int = 0, int = 0);
    Cords(const Cords &);

    int getX();
    int getY();
    void setX(int);
    void setY(int);
    
    Cords& operator=(const Cords &);
    inline bool operator< (const Cords &); // WARNING! checks only rows
    inline bool operator== (const Cords &);
};

inline bool Cords::operator< (const Cords &c){
    return (this->x < c.x);
}

inline bool Cords::operator== (const Cords &c){
    return ((this->x == c.x) && (this->y == c.y));
}

#endif /* CORDS */