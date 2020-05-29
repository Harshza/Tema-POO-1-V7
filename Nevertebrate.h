#ifndef NEVERTEBRATE_H_INCLUDED
#define NEVERTEBRATE_H_INCLUDED

#include "Animal.h"

class Nevertebrata : public Animal{
    std::string rasa;
public:
    explicit Nevertebrata();
    explicit Nevertebrata(const std::string &r);
    Nevertebrata(const Nevertebrata &N);
    virtual ~Nevertebrata()override;

    virtual void print(std::ostream &os)const;
    virtual void read(std::istream &is);

    Nevertebrata& operator=(const Nevertebrata &N);
};

#endif // NEVERTEBRATE_H_INCLUDED
