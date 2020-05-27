#include "SimulareStiva.h"

SimulareStiva::SimulareStiva() = default;

SimulareStiva::SimulareStiva(const int &n, Pereche *v) : q1(n, v) {}

SimulareStiva::SimulareStiva(const SimulareStiva &stk) : q1(stk.q1), q2(stk.q2) {}

SimulareStiva::~SimulareStiva() = default;

SimulareStiva& SimulareStiva::operator=(const SimulareStiva &stk){
    q1 = stk.q1;
    q2 = stk.q2;
    return *this;
}

std::ostream& operator<<(std::ostream &os, const SimulareStiva &M){
    os << M.q1;
    return os;
}

std::istream& operator>>(std::istream &is, SimulareStiva &M){
    int n;
    is >> n;
    Pereche per;
    while(!M.isempty())
        M.pop();
    for(int i = 0; i < n; i++)
    {
        is >> per;
        M.push(per);
    }
    return is;
}

void SimulareStiva::push(const Pereche &per){
    try{ //daca nu puneam asa si lasam exceptiile din clasele de baza,imi schimba ordinea perechilor in stiva :<
        if(q1.find(per) != -1)
            throw "Element already exists.\n";
        q2.push(per);
        while(!q1.isempty())
            q2.push(q1.pop());
        Coada_pereche q = q1;
        q1 = q2;
        q2 = q;
    }catch(const char *e){
        std::cout << e;
    }
}

Pereche SimulareStiva::pop(){
    return q1.pop();
}

Pereche& SimulareStiva::top(){
    return q1.front();
}

bool SimulareStiva::isempty(){
    return q1.isempty();
}
