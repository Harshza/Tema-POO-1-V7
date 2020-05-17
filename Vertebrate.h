#ifndef VERTEBRATE_H_INCLUDED
#define VERTEBRATE_H_INCLUDED

#include "Animal.h"

class Vertebrata : public Animal{
public:
    Vertebrata();
    ~Vertebrata();
    virtual void print(std::ostream &os)const=0;
    virtual void read(std::istream &is)=0;
};

#endif // VERTEBRATE_H_INCLUDED
