#ifndef PASARI_H_INCLUDED
#define PASARI_H_INCLUDED

#include "Vertebrate.h"

class Pasare : public Vertebrata{
public:
    explicit Pasare();
    explicit Pasare(bool rap, double l);
    Pasare(const Pasare &P);
    virtual ~Pasare()override;
    virtual void print(std::ostream &os) const;
    virtual std::string getRasa()const;
    friend std::istream& operator>>(std::istream &is,Pasare &P);
    Pasare& operator=(const Pasare &P);
};

#endif // PASARI_H_INCLUDED
