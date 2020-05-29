#include "Vertebrate.h"

std::string Translatie(Rasa r){
 switch(r)
  {
  case peste: return "peste";
  case pasare: return "pasare";
  case mamifer: return "mamifer";
  default: return "reptila";
  }
}

Vertebrata::Vertebrata() : rasa(mamifer), rapitor(false), lungime(0){

}

Vertebrata::Vertebrata(const std::string &r, bool rap, double l) : rapitor(rap), lungime(l){
    auto i = conv.find(r);
    rasa = i->second;
    try{
        if(lungime < 0)
            throw "Lungimea este un nr pozitiv in general,o punem 0.\n";
        }catch(const char *e){
            std::cout << e;
            lungime = 0;
        }
}

Vertebrata::Vertebrata(const Vertebrata &V) : rasa(V.rasa), rapitor(V.rapitor), lungime(V.lungime){
}

Vertebrata::~Vertebrata() = default;

void Vertebrata::print(std::ostream &os)const{
    os << "Vertebrata de rasa " << Translatie(rasa) << " tip ";
    if(rapitor)
        os << "rapitor ";
    else
        os << "prada ";
    os << "cu lungime de " << lungime << " centimetri.\n";
}

void Vertebrata::read(std::istream &is){
    std::string s;
    is >> s;
    auto i = conv.find(s);
    rasa = i->second;
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

void Vertebrata::setLungime(double l){
    lungime = l;
    try{
        if(lungime < 0)
            throw "Lungimea este un nr pozitiv in general,o punem 0.\n";
    }catch(const char *e){
        std::cout << e;
        lungime = 0;
    }
}

bool Vertebrata::isRapitor(){
    return rapitor;
}

double Vertebrata::getLungime()const{
    return lungime;
}


