#include <iostream>
#include <cstring>

using namespace std;

class Nod
{
    char info;
    Nod* next;
    public:
    Nod(const char& x = '\0', Nod* urm = nullptr) // construct parametrizat pentru initializare
    {
        info = x;
        next = urm;
    }
    ~Nod(){ next = nullptr;}
    inline Nod* Next() const{ return next;} // metode pentru accesarea campurilor private
    inline char Info() const{ return info;}
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
        char ret = varf->Info();
        varf = varf->Next(); // trecem la elementul urm
        delete c; //stergem elementul scos ca sa nu avem memory leaks
        return ret;
    }

    void push(const char& x)
    {
        Nod* c = new Nod(x,varf); // adaugam un nou nod,care duce catre vechiul varf
        varf = c;
    }

    void top()const
    {
        cout << varf->Info();
    }

    char get_top()const
    {
        return varf->Info();
    }

    ~Stiva_de_caractere()
    {
        while(!isempty()) // cat timp mai avem elemente in coada,stergem elementul din varf
            pop();
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
            Ret->push(max(c1->Info(),c2->Info())); // adaug in noua stiva caracterul cu codul ASCII mai mare
            c1 = c1->Next(); //trec la urm elemente
            c2 = c2->Next();
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
    Stiva_de_caractere* stk = new Stiva_de_caractere();
    *stk >> 'c' >> 'b' >> 'a';
    while(!stk->isempty())
    {
        stk->top();
        stk->pop();
    }
    cout << '\n';
    stk->push('c');
    stk->push('b');
    stk->push('a');
    while(!stk->isempty())
    {
        stk->top();
        stk->pop();
    }
    cout << '\n';
    stk->push('c');
    stk->push('b');
    stk->push('a');
    cout << *stk << '\n';
    cout << stk->isempty();
    char v[] = "parola";
    stk->inv(v);
    cout << "\n" << v << " Sir de caractere returnat\n";
    Stiva_de_caractere* stk2 = new Stiva_de_caractere();
    *stk2 >> 'P' >> 'O' >> 'O' >> 'L' >> 'A' >> 'B' >> 'O' >> 'R' >> 'A' >> 'T' >> 'O' >> 'R';
    *stk >> 'E' >> 'X' >> 'A' >> 'M' >> 'E' >> 'N';
    Stiva_de_caractere* stk3;
    (*stk3) = *stk - *stk - *stk2;
    cout << *stk << '\n' << *stk2 << '\n' << *stk3 << '\n';
    *stk >> 'a' >> 'b' >> 'c';
    *stk3 = (*stk - *stk);
    cout << *stk << '\n' << *stk3;
    return 0;
}