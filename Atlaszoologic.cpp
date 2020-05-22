#include "Atlaszoologic.h"

template <typename T>
Atlaszoologic<T>::Atlaszoologic() : v({}), n(0){}

template <typename T>
Atlaszoologic<T>::Atlaszoologic(Atlaszoologic &A) : v(A.v), n(A.n){}

template <typename T>
Atlaszoologic<T>::~Atlaszoologic() = default;

template <typename T>
std::ostream& operator<<(std::ostream& os,const Atlaszoologic<T> &A){
    for(auto x : A.v)
        os << x;
    return os;
}

template <typename T>
std::istream& operator>>(std::istream& is,Atlaszoologic<T> &A){
    is >> A.n;
    T x;
    for(int i = 0; i < A.n; i++)
    {
        is >> x;
        A.v.push_back(x);
    }
    return is;
}

template <typename T>
Atlaszoologic<T>& Atlaszoologic<T>::operator=(Atlaszoologic<T> &A){
    n = A.n;
    v = A.v;
    return *this;
}

template <typename T>
Atlaszoologic<T>& Atlaszoologic<T>::operator+=(T x){
    n++;
    v.push_back(x);
    return *this;
}


////////////////////////////////////////////////////////////////////////////////////

Atlaszoologic<Peste>::Atlaszoologic(): v({}), n(0){
}

Atlaszoologic<Peste>::Atlaszoologic(Atlaszoologic<Peste> &A): v(A.v), n(A.n){
}

std::ostream& operator<<(std::ostream& os,const Atlaszoologic<Peste> &A){
    for(Peste x : A.v)
        os << x;
    return os;
}

std::istream& operator>>(std::istream& is,Atlaszoologic<Peste> &A){
    is >> A.n;
    Peste x;
    for(int i = 0; i < A.n; i++)
    {
        is >> x;
        A.v.push_back(x);
    }
    return is;
}

Atlaszoologic<Peste>& Atlaszoologic<Peste>::operator=(const Atlaszoologic<Peste> &A){
    n = A.n;
    v = A.v;
    return *this;
}

Atlaszoologic<Peste>& Atlaszoologic<Peste>::operator+=(Peste x){
    n++;
    v.push_back(x);
    return *this;
}

int Atlaszoologic<Peste>::PestiRapitoriMari()const{
    int nr = 0;
    for(Peste x : v)
        if(x.getLungime() > 100 && x.isRapitor())
            nr++;
    return nr;
}
