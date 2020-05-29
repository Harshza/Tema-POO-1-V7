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

void Reptila::read(std::istream &is){
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

std::string Reptila::getRasa()const{
    return "reptila";
}


Reptila& Reptila::operator=(const Reptila &P){
    rasa = P.rasa;
    rapitor = P.rapitor;
    lungime = P.lungime;
    return *this;
}

