#ifndef COADA_PERECHE_H_INCLUDED
#define COADA_PERECHE_H_INCLUDED

#include "Multime_pereche.h"

class Coada_pereche : public Multime_pereche
{
    public:
    Coada_pereche();
    Coada_pereche(Coada_pereche &Q);
    ~Coada_pereche();
    bool isempty();
    Pereche& pop();
    Pereche& front();
    void clear();
};

#endif // COADA_PERECHE_H_INCLUDED
