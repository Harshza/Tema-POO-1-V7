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

void Mamifer::read(std::istream &is){
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

std::string Mamifer::getRasa()const{
    return "mamifer";
}


Mamifer& Mamifer::operator=(const Mamifer &P){
    rasa = P.rasa;
    rapitor = P.rapitor;
    lungime = P.lungime;
    return *this;
}

