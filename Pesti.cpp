#include "Pesti.h"

int Peste::nr_rapitori_mari = 0;

Peste::~Peste(){
    if(rapitor && lungime > 100.00)
        nr_rapitori_mari--;
}

Peste::Peste(){

}

Peste::Peste(double l, bool R, bool S) : lungime(l), rapitor(R), apa_sarata(S){
    if(rapitor && lungime > 100.00)
        nr_rapitori_mari++;
}

Peste::Peste(Peste &P) : lungime(P.lungime), rapitor(P.rapitor), apa_sarata(P.apa_sarata){
    if(rapitor && lungime > 100.00)
        nr_rapitori_mari++;
}

void Peste::print(std::ostream &os) const{
    os << "Peste cu lungimea de " << lungime;
    if(rapitor)
        os << " rapitor";
    else
        os << " nerapitor";
    os << " de apa ";
    if(apa_sarata)
        os << " sarata.\n";
    else
        os << " dulce.\n";
}

void Peste::read(std::istream &is){
    if(rapitor && lungime > 100.00)
        nr_rapitori_mari--;
    char s[15];
    is >> lungime >> s;
    if(strcmp(s,"rapitor") == 0)
        rapitor = true;
    else
        rapitor = false;
    is >> s >> s;
    if(strcmp(s,"sarata") == 0)
        apa_sarata = true;
    else
        apa_sarata = false;
}

std::ostream& operator<<(std::ostream &os,const Peste &P){
    P.print(os);
    return os;
}

std::istream& operator>>(std::istream &is,Peste &P){
    P.read(is);
    return is;
}
