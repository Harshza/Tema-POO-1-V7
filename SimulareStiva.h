#ifndef SIMULARESTIVA_H_INCLUDED
#define SIMULARESTIVA_H_INCLUDED

#include "Coada_pereche.h"

class SimulareStiva{
    Coada_pereche q1, q2;
public:
    SimulareStiva();
    SimulareStiva(const int &n, Pereche *v);
    SimulareStiva(const SimulareStiva &stk);
    ~SimulareStiva();
    SimulareStiva& operator=(const SimulareStiva &stk);
    friend std::ostream& operator<<(std::ostream &os, const SimulareStiva &M);
    friend std::istream& operator>>(std::istream &is, SimulareStiva &M);
    void push(const Pereche &per);
    Pereche pop();
    Pereche& top();
    bool isempty();
};

#endif // SIMULARESTIVA_H_INCLUDED
