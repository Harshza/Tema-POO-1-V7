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

void Peste::read(std::istream &is){
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

std::string Peste::getRasa()const{
    return "peste";
}


Peste& Peste::operator=(const Peste &P){
    rasa = P.rasa;
    rapitor = P.rapitor;
    lungime = P.lungime;
    return *this;
}

