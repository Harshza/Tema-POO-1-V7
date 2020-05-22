#ifndef NEVERTEBRATE_H_INCLUDED
#define NEVERTEBRATE_H_INCLUDED

#include "Animal.h"

class Nevertebrata : public Animal{
    std::string rasa;
public:
    explicit Nevertebrata();
    explicit Nevertebrata(std::string r);
    Nevertebrata(const Nevertebrata &V);
    virtual ~Nevertebrata()override;
    virtual void print(std::ostream &os)const;
    friend std::istream& operator>>(std::istream &is,Nevertebrata &N);
    Nevertebrata& operator=(const Nevertebrata &P);
};

#endif // NEVERTEBRATE_H_INCLUDED
