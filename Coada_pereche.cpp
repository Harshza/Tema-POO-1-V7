#include "Coada_pereche.h"

Coada_pereche::Coada_pereche() = default;

Coada_pereche::Coada_pereche(const int &n, Pereche *v) : Multime_pereche(n, v) {}

Coada_pereche::Coada_pereche(const Coada_pereche &stk) : Multime_pereche(stk.nr, stk.p) {}

Coada_pereche::~Coada_pereche() = default;

void Coada_pereche::print(std::ostream &os)const{
    os << "In coada avem:\n";
    for(int i = 0; i < nr; i++)
        os << p[i] << ' ';
}

void Coada_pereche::read(std::istream &is){
    Multime_pereche::read(is);
}

Pereche Coada_pereche::pop(){
    Pereche ret = p[0];
    pop_front();
    return ret;
}

Pereche& Coada_pereche::front(){
    try{
        if(nr == 0)
            throw "No elements.\n";
        return p[0];
    }catch(const char *e){
        std::cout << e;
        return p[0];
    }
}

