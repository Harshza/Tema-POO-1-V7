#ifndef COADA_PERECHE_H_INCLUDED
#define COADA_PERECHE_H_INCLUDED

#include "Multime_pereche.h"

class Coada_pereche : public Multime_pereche
{
    public:
    Coada_pereche();
    Coada_pereche(int n, Pereche *v);
    Coada_pereche(const Coada_pereche &Q);
    ~Coada_pereche();
    virtual void print(std::ostream &os)const;
    virtual void read(std::istream &is);
    Pereche pop();
    Pereche& front();
};

#endif // COADA_PERECHE_H_INCLUDED
