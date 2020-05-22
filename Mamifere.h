#ifndef MAMIFERE_H_INCLUDED
#define MAMIFERE_H_INCLUDED

#include "Vertebrate.h"

class Mamifer : public Vertebrata{
public:
    explicit Mamifer();
    explicit Mamifer(bool rap, double l);
    Mamifer(const Mamifer &P);
    virtual ~Mamifer()override;
    virtual void print(std::ostream &os) const;
    virtual std::string getRasa()const;
    friend std::istream& operator>>(std::istream &is,Mamifer &P);
    Mamifer& operator=(const Mamifer &P);
};

#endif // MAMIFERE_H_INCLUDED
