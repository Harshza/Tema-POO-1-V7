#include "Stiva_pereche.h"

Stiva_pereche::Stiva_pereche(){

}

Stiva_pereche::Stiva_pereche(Stiva_pereche &stk){

}

Stiva_pereche::~Stiva_pereche(){

}

std::ostream& operator<<(std::ostream &os, const Stiva_pereche &stk){
    for(int i = stk.nr - 1; i >= 0; i--)
        os << stk.p[i] << ' ';
    return os;

}


bool Stiva_pereche::isempty(){
    return !nr;
}

Pereche& Stiva_pereche::pop(){
    pop_back();
    if(p)
        return p[nr];
}

Pereche& Stiva_pereche::top(){
    try{
        if(nr == 0)
            throw "No elements.\n";
        return p[nr - 1];
    }catch(const char *e){
        std::cout << e;
    }
}

void Stiva_pereche::clear(){
    nr = capacity = 0;
    Pereche *del = p;
    p = nullptr;
    delete[] del;
}
