#ifndef MULTIME_PERECHE_H_INCLUDED
#define MULTIME_PERECHE_H_INCLUDED

#include "Pereche.h"

class Multime_pereche{
protected:
    static const int INITIAL_CAPACITY = 10;
    int nr,capacity;
    Pereche *p;
public:
    Multime_pereche();
    Multime_pereche(int n, Pereche *v);
    Multime_pereche(const Multime_pereche &M);
    ~Multime_pereche();
    Multime_pereche& operator=(const Multime_pereche &M);
    friend std::ostream& operator<<(std::ostream &os, const Multime_pereche &M);
    virtual void print(std::ostream &os)const;
    virtual void read(std::istream &is);
    friend std::istream& operator>>(std::istream &is, Multime_pereche &M);
    int find(const Pereche &per);
    void push(const Pereche &per);
    void pop(const Pereche &per);
    void pop_back();
    void pop_front();
    bool isempty();
    void clear();
};

#endif // MULTIME_PERECHE_H_INCLUDED
