#include "Pasari.h"

Pasare::~Pasare() = default;

Pasare::Pasare() : Vertebrata("pasare", false, 0){
}

Pasare::Pasare(bool rap, double l) : Vertebrata("pasare", rap, l){
}

Pasare::Pasare(const Pasare &P) : Vertebrata(Translatie(P.rasa), P.rapitor, P.lungime){
}

void Pasare::print(std::ostream &os) const{
    Vertebrata::print(os);
}

std::string Pasare::getRasa()const{
    return "pasare";
}

std::istream& operator>>(std::istream &is,Pasare &P){
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

Pasare& Pasare::operator=(const Pasare &P){
    rasa = P.rasa;
    rapitor = P.rapitor;
    lungime = P.lungime;
    return *this;
}
