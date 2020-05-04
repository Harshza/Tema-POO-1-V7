#ifndef STIVA_PERECHE_H_INCLUDED
#define STIVA_PERECHE_H_INCLUDED

#include "Multime_pereche.h"

class Stiva_pereche : public Multime_pereche
{
    public:
    Stiva_pereche();
    Stiva_pereche(Stiva_pereche &stk);
    ~Stiva_pereche();
    friend std::ostream& operator<<(std::ostream &os, const Stiva_pereche &stk);
    bool isempty();
    Pereche& pop();
    Pereche& top();
    void clear();
};
#endif // STIVA_PERECHE_H_INCLUDED
