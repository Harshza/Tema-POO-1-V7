#include "Reptile.h"

Reptila::~Reptila() = default;

Reptila::Reptila() : Vertebrata("reptila", false, 0){
}

Reptila::Reptila(bool rap, double l) : Vertebrata("reptila", rap, l){
}

Reptila::Reptila(const Reptila &P) : Vertebrata(Translatie(P.rasa), P.rapitor, P.lungime){
}

void Reptila::print(std::ostream &os) const{
    Vertebrata::print(os);
}

std::string Reptila::getRasa()const{
    return "reptila";
}

std::istream& operator>>(std::istream &is,Reptila &P){
    std::string r;
    is >> r;
    auto i = conv.find(r);
    P.rasa = i->second;
    is >> r;
    if(r == "rapitor")
        P.rapitor = true;
    else
        P.rapitor = false;
    is >> P.lungime;
    return is;
}

Reptila& Reptila::operator=(const Reptila &P){
    rasa = P.rasa;
    rapitor = P.rapitor;
    lungime = P.lungime;
    return *this;
}
