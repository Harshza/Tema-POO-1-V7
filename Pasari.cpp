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

void Pasare::read(std::istream &is){
    std::string s;
    is >> s;
    if(s == "rapitor")
        rapitor = true;
    else
        rapitor = false;
    is >> lungime;
    try{
        if(lungime < 0)
            throw "Lungimea este un nr pozitiv in general,o punem 0.\n";
        }catch(const char *e){
            std::cout << e;
            lungime = 0;
        }
}

std::string Pasare::getRasa()const{
    return "pasare";
}


Pasare& Pasare::operator=(const Pasare &P){
    rasa = P.rasa;
    rapitor = P.rapitor;
    lungime = P.lungime;
    return *this;
}

