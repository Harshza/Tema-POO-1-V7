#include "Pesti.h"

Peste::~Peste() = default;

Peste::Peste() : Vertebrata("peste", false, 0){
}

Peste::Peste(bool rap, double l) : Vertebrata("peste", rap, l){
}

Peste::Peste(const Peste &P) : Vertebrata(Translatie(P.rasa), P.rapitor, P.lungime){
}

void Peste::print(std::ostream &os) const{
    Vertebrata::print(os);
}

std::string Peste::getRasa()const{
    return "peste";
}

std::istream& operator>>(std::istream &is,Peste &P){
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

Peste& Peste::operator=(const Peste &P){
    rasa = P.rasa;
    rapitor = P.rapitor;
    lungime = P.lungime;
    return *this;
}
