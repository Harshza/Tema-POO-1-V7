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

Vertebrata::Vertebrata(std::string r, bool rap, double l) : rapitor(rap), lungime(l){
    auto i = conv.find(r);
    rasa = i->second;
    try{
        if(lungime < 0)
            throw "Lungimea este un nr pozitiv in general,il punem 0.\n";
        }catch(const char *e){
            std::cout << e;
            lungime = 0;
        }
}

Vertebrata::Vertebrata(const Vertebrata &V) : rasa(V.rasa), rapitor(V.rapitor), lungime(V.lungime){
}

Vertebrata::~Vertebrata() = default;

void Vertebrata::print(std::ostream &os)const{
    os << "Vertebrata de rasa " << Translatie(rasa) << " cu lungime de " << lungime << " centimetri.\n";
}

void Vertebrata::setLungime(double l){
    lungime = l;
}

bool Vertebrata::isRapitor(){
    return rapitor;
}

double Vertebrata::getLungime()const{
    return lungime;
}


