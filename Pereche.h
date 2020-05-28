#ifndef PERECHE_H_INCLUDED
#define PERECHE_H_INCLUDED

#include <iostream>

class Pereche{
    int x, y;
public:
    Pereche();
    Pereche(int _x, int _y);
    Pereche(const Pereche &p);
    ~Pereche();
    friend std::ostream& operator<<(std::ostream &os, const Pereche &p);
    friend std::istream& operator>>(std::istream &is, Pereche &p);
    Pereche& operator=(const Pereche &p);
    int first() const;
    int second() const;
    void setfirst(int _x);
    void setsecond(int _y);
    bool operator==(const Pereche &p);
    bool operator!=(const Pereche &p);
    Pereche& operator+(const Pereche &p);
    Pereche& operator+(int i);
    friend Pereche make_pereche(int a, int b);
};

#endif // PERECHE_H_INCLUDED
