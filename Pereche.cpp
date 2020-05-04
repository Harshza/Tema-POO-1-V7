#include "Pereche.h"

Pereche::Pereche(){
    x = 0;
    y = 0;
}

Pereche::Pereche(int _x, int _y) : x(_x), y(_y) {}

Pereche::Pereche(Pereche &p) : x(p.x), y(p.y) {}

Pereche::~Pereche(){}

std::ostream& operator<<(std::ostream &os, const Pereche &p){
    os << '(' << p.x << ", " << p.y << ')';
    return os;
}

std::istream& operator>>(std::istream &is, Pereche &p){
    is >> p.x >> p.y;
    return is;
}

Pereche& Pereche::operator=(const Pereche &p){
    x = p.x;
    y = p.y;
    return *this;
}

int Pereche::first() const{
    return x;
}

int Pereche::second() const{
    return y;
}

void Pereche::setfirst(int _x){
    x = _x;
}

void Pereche::setsecond(int _y){
    y = _y;
}

bool Pereche::operator==(const Pereche &p){
    return (x == p.x && y == p.y);
}

bool Pereche::operator!=(const Pereche &p){
    return (x != p.x || y != p.y);
}

