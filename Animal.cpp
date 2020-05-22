#include "Animal.h"

int Animal::nr = 0;

Animal::Animal(){
    nr++;
}

Animal::~Animal(){
    nr--;
}

void Animal::print(std::ostream &os)const{
    return;
}

std::ostream& operator<<(std::ostream &os,const Animal &A){
    A.print(os);
    return os;
}

Animal::nrAnimale(){
    return nr;
}
