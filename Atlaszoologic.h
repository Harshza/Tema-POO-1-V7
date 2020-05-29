#ifndef ATLASZOOLOGIC_H_INCLUDED
#define ATLASZOOLOGIC_H_INCLUDED

#include "Pesti.h"
#include <vector>


template <typename T>
class Atlaszoologic{
    std::vector<T> v;
    int n;
public:
    explicit Atlaszoologic();
    Atlaszoologic(Atlaszoologic<T> &A);
    ~Atlaszoologic();

    template<typename U>
    friend std::ostream& operator<<(std::ostream& os,const Atlaszoologic<U> &A);

    template<typename U>
    friend std::istream& operator>>(std::istream& is,Atlaszoologic<U> &A);

    Atlaszoologic<T>& operator=(Atlaszoologic<T> &A);
    Atlaszoologic<T>& operator+=(T x);

};

template <>
class Atlaszoologic<Peste>{
    std::vector<Peste> v;
    int n;
public:
    explicit Atlaszoologic<Peste>();
    Atlaszoologic<Peste>(Atlaszoologic<Peste> &A);
    ~Atlaszoologic<Peste>();

    friend std::ostream& operator<<(std::ostream& os,const Atlaszoologic<Peste> &A);
    friend std::istream& operator>>(std::istream& is,Atlaszoologic<Peste> &A);

    Atlaszoologic<Peste>& operator=(const Atlaszoologic<Peste> &A);
    Atlaszoologic<Peste>& operator+=(Peste x);

    int PestiRapitoriMari()const;
};
#endif // ATLASZOOLOGIC_H_INCLUDED

