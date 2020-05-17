#ifndef PESTI_H_INCLUDED
#define PESTI_H_INCLUDED

#include "Vertebrate.h"

class Peste : public Vertebrata{
    double lungime;
    bool rapitor, apa_sarata;
    static int nr_rapitori_mari;
public:
    Peste();
    Peste(double l, bool R, bool S);
    Peste(Peste &P);
    ~Peste();
    virtual void print(std::ostream &os) const;
    virtual void read(std::istream &is);
    friend std::ostream& operator<<(std::ostream &os,const Peste &P);
    friend std::istream& operator>>(std::istream &is,Peste &P);
    void setLungime(double l);
    double getLungime() const;
    void setRapitor(const char* r);
    bool isRapitor() const;
    void setApa(const char* a);
    bool apaSarata() const;
    static int Rapitori();
};

#endif // PESTI_H_INCLUDED
