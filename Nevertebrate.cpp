#include "Nevertebrate.h"

Nevertebrata::Nevertebrata() = default;

Nevertebrata::Nevertebrata(const std::string &r) : rasa(r){
}

Nevertebrata::Nevertebrata(const Nevertebrata &V) : rasa(V.rasa){}

Nevertebrata::~Nevertebrata() = default;

void Nevertebrata::print(std::ostream &os)const{
    os << "Nevertebrata de rasa " << rasa << ".\n";
}

void Nevertebrata::read(std::istream &is){
    is >> rasa;
}

Nevertebrata& Nevertebrata::operator=(const Nevertebrata &P){
    rasa = P.rasa;
    return *this;
}
