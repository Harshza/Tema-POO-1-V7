#include "Mamifere.h"

Mamifer::~Mamifer() = default;

Mamifer::Mamifer() : Vertebrata("mamifer", false, 0){
}

Mamifer::Mamifer(bool rap, double l) : Vertebrata("mamifer", rap, l){
}

Mamifer::Mamifer(const Mamifer &P) : Vertebrata(Translatie(P.rasa), P.rapitor, P.lungime){
}

void Mamifer::print(std::ostream &os) const{
    Vertebrata::print(os);
}

std::string Mamifer::getRasa()const{
    return "mamifer";
}

std::istream& operator>>(std::istream &is,Mamifer &P){
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

Mamifer& Mamifer::operator=(const Mamifer &P){
    rasa = P.rasa;
    rapitor = P.rapitor;
    lungime = P.lungime;
    return *this;
}
