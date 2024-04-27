#include <iostream>
#include "cords.h"
using namespace std;

int main(){

    Cords c1(3,5);
    Cords c2 = {4,4};

    cout << "c1 (" << c1.getX() << "," << c1.getY() << ")\n";
    cout << "c2 (" << c2.getX() << "," << c2.getY() << ")\n";
    cout << "c1 < c2 : " << (c1 < c2) << endl;
    cout << "c2 < c1 : " << (c2 < c1) << endl;

    cout << "c1 = c2\n";
    c1 = c2; 
    cout << "c1 (" << c1.getX() << "," << c1.getY() << ")\n";
    cout << "c2 (" << c2.getX() << "," << c2.getY() << ")\n";
    cout << "c1 < c2 : " << (c1 < c2) << endl;


    return 0;
}