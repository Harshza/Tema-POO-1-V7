#ifndef VERTEBRATE_H_INCLUDED
#define VERTEBRATE_H_INCLUDED

#include "Animal.h"

enum Rasa{
    peste, pasare, mamifer, reptila
};

std::string Translatie(Rasa r);


static std::unordered_map<std::string,Rasa>const conv = {{"peste", Rasa::peste}, {"pasare", Rasa::pasare},
                                                         {"mamifer", Rasa::mamifer}, {"reptila", Rasa::reptila}};

class Vertebrata : public Animal{
protected:
    Rasa rasa;
    bool rapitor;
    double lungime;
public:
    explicit Vertebrata();
    explicit Vertebrata(std::string r, bool rap, double l);
    Vertebrata(const Vertebrata &V);
    virtual ~Vertebrata() override;
    virtual void print(std::ostream &os)const;
    void setLungime(double l);
    virtual std::string getRasa()const = 0;
    bool isRapitor();
    double getLungime()const;
};

#endif // VERTEBRATE_H_INCLUDED
