#include "Animal.h"

int Animal::nr = 0;

Animal::Animal(){
    nr++;
}

Animal::~Animal(){
    nr--;
}

Animal::nrAnimale(){
    return nr;
}
