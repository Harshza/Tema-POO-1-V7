#include "Nevertebrate.h"

Nevertebrata::Nevertebrata() = default;

Nevertebrata::Nevertebrata(std::string r) : rasa(r){
}

Nevertebrata::Nevertebrata(const Nevertebrata &V) : rasa(V.rasa){}

Nevertebrata::~Nevertebrata() = default;

void Nevertebrata::print(std::ostream &os)const{
    os << "Nevertebrata de rasa " << rasa << ".\n";
}

std::istream& operator>>(std::istream &is,Nevertebrata &N){
    is >> N.rasa;
    return is;
}

Nevertebrata& Nevertebrata::operator=(const Nevertebrata &P){
    rasa = P.rasa;
    return *this;
}
