#ifndef ANIMAL_H_INCLUDED
#define ANIMAL_H_INCLUDED

#include <iostream>
#include <string>
#include <unordered_map>

class Animal{
    static int nr;
public:
    explicit Animal();
    virtual ~Animal();
    virtual void print(std::ostream &os)const=0;
    virtual void read(std::istream &is)=0;
    friend std::ostream& operator<<(std::ostream &os, const Animal &A);
    friend std::istream& operator>>(std::istream &is, Animal &A);
    int static nrAnimale();
};

#endif // ANIMAL_H_INCLUDED
