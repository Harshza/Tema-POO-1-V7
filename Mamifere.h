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
    virtual void read(std::istream &is);

    virtual std::string getRasa()const;
    Mamifer& operator=(const Mamifer &P);
};

#endif // MAMIFERE_H_INCLUDED

