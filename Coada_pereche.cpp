#include "Coada_pereche.h"

Coada_pereche::Coada_pereche(){

}

Coada_pereche::Coada_pereche(Coada_pereche &Q){

}

Coada_pereche::~Coada_pereche(){

}

bool Coada_pereche::isempty(){
    return !nr;
}

Pereche& Coada_pereche::pop(){
    pop_front();
    if(p)
        return p[0];
}

Pereche& Coada_pereche::front(){
    try{
        if(nr == 0)
            throw "No elements.\n";
        return p[0];
    }catch(const char *e){
        std::cout << e;
    }
}

void Coada_pereche::clear(){
    nr = capacity = 0;
    Pereche *del = p;
    p = nullptr;
    delete[] del;
}
