#include "Stiva_pereche.h"

Stiva_pereche::Stiva_pereche() = default;

Stiva_pereche::Stiva_pereche(int n, Pereche *v) : Multime_pereche(n, v) {}

Stiva_pereche::Stiva_pereche(const Stiva_pereche &stk) : Multime_pereche(stk.nr, stk.p) {}

Stiva_pereche::~Stiva_pereche() = default;

void Stiva_pereche::print(std::ostream &os)const{
    os << "In stiva avem:\n";
    for(int i = nr - 1; i >= 0; i--)
        os << p[i] << ' ';
}

void Stiva_pereche::read(std::istream &is){
    Multime_pereche::read(is);
}

Pereche& Stiva_pereche::pop(){
    pop_back();
    return p[nr];
}

Pereche& Stiva_pereche::top(){
    try{
        if(nr == 0)
            throw "No elements.\n";
        return p[nr - 1];
    }catch(const char *e){
        std::cout << e;
        return p[nr];
    }
}
