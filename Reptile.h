#ifndef REPTILE_H_INCLUDED
#define REPTILE_H_INCLUDED

#include "Vertebrate.h"

class Reptila : public Vertebrata{
public:
    explicit Reptila();
    explicit Reptila(bool rap, double l);
    Reptila(const Reptila &P);
    virtual ~Reptila()override;
    virtual void print(std::ostream &os) const;
    virtual std::string getRasa()const;
    friend std::istream& operator>>(std::istream &is,Reptila &P);
    Reptila& operator=(const Reptila &P);
};

#endif // REPTILE_H_INCLUDED
