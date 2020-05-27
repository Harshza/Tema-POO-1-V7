#include "Multime_pereche.h"

Multime_pereche::Multime_pereche(){
    nr = 0;
    capacity = 10;
    p = new Pereche[capacity];
}

Multime_pereche::Multime_pereche(const int &n, Pereche *v){
    nr = 0;
    capacity = 10;
    p = new Pereche[capacity];
    for(int i = 0; i < n; i++)
        push(v[i]); //folosim push in caz ca avem dubluri in v
}

Multime_pereche::Multime_pereche(const Multime_pereche &M): nr(M.nr), capacity(M.capacity){
    p = new Pereche[capacity];
    for(int i = 0; i < nr; i++)
        p[i] = M.p[i];
}

Multime_pereche::~Multime_pereche(){
    delete[] p;
}

Multime_pereche& Multime_pereche::operator=(const Multime_pereche &M){
    nr = M.nr;
    if(capacity < nr)
    {
        capacity = M.capacity;
        Pereche *del = p;
        p = new Pereche[capacity];
        delete[] del;
    }

    for(int i = 0; i < nr; i++)
        p[i] = M.p[i];
    return *this;
}

std::ostream& operator<<(std::ostream &os, const Multime_pereche &M){
    M.print(os);
    return os;
}

std::istream& operator>>(std::istream &is, Multime_pereche &M){
    M.read(is);
    return is;
}

int Multime_pereche::find(const Pereche &per){ //folosim pt a verifica proprietatea de multime
    for(int i = 0; i < nr; i++)
        if(p[i] == per)
            return i + 1;
    return -1; //nu am gasit elementul in multime
}

void Multime_pereche::push(const Pereche &per){
    try{
        int poz = find(per);
        if(poz != -1)
            throw "Element already exists.\n";
        if(nr == capacity)
        {
            Pereche *del = p;
            capacity *= 2;
            p = new Pereche[capacity];
            for(int i = 0; i < nr; i++)
                p[i] = del[i];
            delete[] del;
        }
        p[nr] = per;
        nr++;
    }catch(const char *e){
        std::cout << e;
    }
}

void Multime_pereche::pop_back(){
    try{
        if(nr == 0)
            throw "No elements to erase.\n";
        nr--;
    }catch(const char *e){
        std::cout << e;
    }
}

void Multime_pereche::pop_front(){
    try{
        if(nr == 0)
            throw "No elements to erase.\n";
        nr--;
        for(int i = 0; i < nr; i++)
            p[i] = p[i + 1];
    }catch(const char *e){
        std::cout << e;
    }
}

void Multime_pereche::pop(const Pereche &per){
    try{
        if(nr == 0)
            throw "No elements to erase.\n";
        int poz = find(per);
        if(poz == -1)
            throw "Element not found.\n";
        nr--;
        for(int i = poz - 1; i < nr; i++)
            p[i] = p[i + 1];
    }catch(const char *e){
        std::cout << e;
    }
}

void Multime_pereche::print(std::ostream &os)const{
    os << "In multime avem:\n";
    for(int i = 0; i < nr; i++)
        os << p[i] << ' ';
}


void Multime_pereche::read(std::istream &is){
    int n;
    is >> n;
    nr = 0; //adaugam elemente de la poz 0 (incepem cu 0 elemente,ca le suprascriem pe cele vechi)
    Pereche per;
    for(int i = 0; i < n; i++)
    {
        is >> per;
        push(per); //pastram proprietatea de multime
    }
}

bool Multime_pereche::isempty(){
    return !nr;
}

void Multime_pereche::clear(){
    nr = 0;
    capacity = 10; //ducem inapoi in "starea initiala" a multimii
    Pereche *del = p;
    p = new Pereche[capacity];
    delete[] del;
}
