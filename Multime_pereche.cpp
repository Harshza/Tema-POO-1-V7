#include "Multime_pereche.h"

Multime_pereche::Multime_pereche(){
    nr = capacity = 0;
    p = nullptr;
}

Multime_pereche::Multime_pereche(Multime_pereche &M): nr(M.nr){
    capacity = nr;
    p = new Pereche[capacity];
    for(int i = 0; i < capacity; i++)
        p[i] = M.p[i];
}

Multime_pereche::~Multime_pereche(){
    delete[] p;
}

std::ostream& operator<<(std::ostream &os, const Multime_pereche &M){
    for(int i = 0; i < M.nr; i++)
        os << M.p[i] << ' ';
    return os;
}

std::istream& operator>>(std::istream &is, Multime_pereche &M){
    is >> M.capacity;
    M.nr = 0;

    Pereche *del = M.p;
    M.p = new Pereche[M.capacity];
    delete[] del;

    Pereche per;
    for(int i = 0; i < M.capacity; i++)
    {
        is >> per;
        M.add(per);
    }
    return is;
}

Multime_pereche& Multime_pereche::operator=(const Multime_pereche &M){
    nr = M.nr;
    capacity = nr;

    Pereche *del = p;
    p = new Pereche[capacity];
    delete[] del;

    for(int i = 0; i < nr; i++)
        p[i] = M.p[i];
    return *this;
}

int Multime_pereche::find(const Pereche &per){
    for(int i = 0; i < nr; i++)
        if(p[i] == per)
            return i + 1;
    return -1;
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
        for(int i = poz; i < nr; i++)
            p[i] = p[i + 1];
    }catch(const char *e){
        std::cout << e;
    }
}

void Multime_pereche::add(const Pereche &per){
    try{
        int poz = find(per);
        if(poz != -1)
            throw "Element already exists.\n";
        if(nr == capacity)
        {
            Pereche *del = p;
            capacity++;
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


