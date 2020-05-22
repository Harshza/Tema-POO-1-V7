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
    virtual void print(std::ostream &os)const;
    friend std::ostream& operator<<(std::ostream &os,const Animal &A);
    static int nrAnimale();
};

#endif // ANIMAL_H_INCLUDED
