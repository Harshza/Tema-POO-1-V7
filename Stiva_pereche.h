#ifndef STIVA_PERECHE_H_INCLUDED
#define STIVA_PERECHE_H_INCLUDED

#include "Multime_pereche.h"

class Stiva_pereche : public Multime_pereche
{
    public:
    Stiva_pereche();
    Stiva_pereche(int n, Pereche *v);
    Stiva_pereche(const Stiva_pereche &stk);
    ~Stiva_pereche();
    virtual void print(std::ostream &os)const;
    virtual void read(std::istream &is);
    Pereche& pop();
    Pereche& top();
};
#endif // STIVA_PERECHE_H_INCLUDED
