#include "Animal.h"

int Animal::nr = 0;

Animal::Animal(){
    nr++;
}

Animal::~Animal(){
    nr--;
}

std::ostream& operator<<(std::ostream &os,const Animal &A){
    A.print(os);
    return os;
}

std::istream& operator>>(std::istream &is, Animal &A){
    A.read(is);
    return is;
}

int Animal::nrAnimale(){
    return nr;
}
