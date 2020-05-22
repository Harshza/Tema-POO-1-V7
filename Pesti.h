#ifndef PESTI_H_INCLUDED
#define PESTI_H_INCLUDED

#include "Vertebrate.h"

class Peste : public Vertebrata{
public:
    explicit Peste();
    explicit Peste(bool rap, double l);
    Peste(const Peste &P);
    virtual ~Peste()override;
    virtual void print(std::ostream &os) const;
    virtual std::string getRasa()const;
    friend std::istream& operator>>(std::istream &is,Peste &P);
    Peste& operator=(const Peste &P);
};

#endif // PESTI_H_INCLUDED
