#ifndef ANIMAL_H_INCLUDED
#define ANIMAL_H_INCLUDED

#include <iostream>
#include <string.h>

class Animal{
    static int nr;
public:
    Animal();
    ~Animal();
    virtual void print(std::ostream &os)const=0;
    virtual void read(std::istream &is)=0;
    static int nrAnimale();
};

#endif // ANIMAL_H_INCLUDED
