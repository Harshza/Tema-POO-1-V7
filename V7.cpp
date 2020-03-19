#include <iostream>
#include <cstring>

using namespace std;

class Nod
{
    char info;
    Nod* next;
    public:
    Nod(const char x = '\0', Nod* urm = nullptr) // construct parametrizat pentru initializare
    {
        info = x;
        next = urm;
    }
    ~Nod(){ 
        next = nullptr;
    }
    inline Nod* get_next() const // metode pentru accesarea campurilor private
    { 
        return next;
    }
    inline char get_info() const
    { 
        return info;
    }
};

class Stiva_de_caractere
{
    Nod* varf;

public:

    Stiva_de_caractere(){ varf = nullptr;} //constructor initializare stiva vida

    bool isempty() const { return !varf;}

    char pop() // scoatem elementul din varful stivei si returnam valoarea
    {
        Nod* c = varf;
        char ret = varf->get_info();
        varf = varf->get_next(); // trecem la elementul urm
        delete c; //stergem elementul scos ca sa nu avem memory leaks
        return ret;
    }

    void push(const char& x)
    {
        Nod* c = new Nod(x,varf); // adaugam un nou nod,care duce catre vechiul varf
        varf = c;
    }

    void print_top()const
    {
        cout << varf->get_info();
    }

    char get_top()const
    {
        return varf->get_info();
    }

    ~Stiva_de_caractere()
    {
        while(!isempty()) // cat timp mai avem elemente in coada,stergem elementul din varf
            pop();
        varf = nullptr;
    }

    Stiva_de_caractere& operator>>(const char& x)
    {
        push(x);
        return *this;
    }
    friend ostream& operator<<(ostream& os, const Stiva_de_caractere& stk);

    void inv(char *s) // inversarea unui sir de caractere
    {
        int lung = strlen(s);
        for(int i = 0; i < lung; i++)
            *this >> s[i]; // bagam toate caracterele din sir in stiva
        for(int i = 0; i < lung; i++)
            s[i] = pop(); // cum stiva functioneaza pe principiul FILO,pur si simplu adaugam elementele inapoi in sir
    }

    Stiva_de_caractere& operator-(const Stiva_de_caractere& S)
    {
        Stiva_de_caractere* Ret = new Stiva_de_caractere();
        Nod* c1 = this->varf,* c2 = S.varf;
        while(c1 && c2) // parcurg ambele stive cu pointeri pana una din ele se termina
        {
            Ret->push(max(c1->get_info(),c2->get_info())); // adaug in noua stiva caracterul cu codul ASCII mai mare
            c1 = c1->get_next(); //trec la urm elemente
            c2 = c2->get_next();
        }
        return *Ret;
    }
};

ostream& operator<<(ostream& os, Stiva_de_caractere& stk)
{
    while(!stk.isempty())
        os << stk.pop();
    return os;
}



int main()
{
    Stiva_de_caractere stk;
    stk >> 'c' >> 'b' >> 'a';
    cout << '\n';
    stk.push('c');
    stk.push('b');
    stk.push('a');
    cout << '\n';
    stk.push('c');
    stk.push('b');
    stk.push('a');
    cout << stk << '\n';
    cout << stk.isempty();
    char v[] = "parola";
    stk.inv(v);
    cout <<"\nSir de caractere returnat:" << v << "\n";
    Stiva_de_caractere stk2;
    stk2 >> 'P' >> 'O' >> 'O' >> 'L' >> 'A' >> 'B' >> 'O' >> 'R' >> 'A' >> 'T' >> 'O' >> 'R';
    stk >> 'E' >> 'X' >> 'A' >> 'M' >> 'E' >> 'N';
    Stiva_de_caractere stk3;
    stk3 = stk - stk - stk2;
    cout << stk << '\n' << stk2 << '\n' << stk3 << '\n';
    stk >> 'a' >> 'b' >> 'c';
    stk3 = stk - stk;
    cout << stk << '\n' << stk3 << "\n";
    cout << "A mers modificarea";
    return 0;
}