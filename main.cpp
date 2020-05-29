#include <iostream>
#include <list>
#include "Nevertebrate.h"
#include "Pasari.h"
#include "Reptile.h"
#include "Mamifere.h"
#include "Pesti.h"
#include "Atlaszoologic.h"

int main()
{
    std::list<Animal*> L;

    int n;
    std::cout << "Inserati cate animale vreti sa cititi\n";
    std::cin >> n;

    std::cout << "Cititi tipul de animal(vertebrat/nevertebrat) apoi rasa lui\n";
    std::cout << "In cazul vertebratelor,cititi si daca sunt rapitori si lungimea lor\n";
    Animal *a;
    for(int i = 0; i < n; i++)
    {
        std::string s;
        std::cin >> s;
        if(s == "vertebrat")
        {
            std::string r;
            std::cin >> r;
            if(r == "mamifer"){
                a = new Mamifer();
                std::cin >> *a;
                L.push_back(a);
            }
            else if(r == "reptila"){
                a = new Reptila();
                std::cin >> *a;
                L.push_back(a);
            }
            else if(r == "pasare"){
                a = new Pasare();
                std::cin >> *a;
                L.push_back(a);
            }
            else if(r == "peste"){
                a = new Peste();
                std::cin >> *a;
                L.push_back(a);
            }
        }
        else if(s == "nevertebrat")
        {
            a = new Nevertebrata();
            std::cin >> *a;
            L.push_back(a);
        }
    }

    for(auto& i : L){
        std::cout << *i << '\n';
    }

    Atlaszoologic<Peste> A;
    std::cout << "\nCitim nr de pesti din atlas,urmat de rapitor/nerapitor si dimensiunea fiecarui peste.\n";
    std::cin >> A;
    std::cout << A.PestiRapitoriMari() << '\n';
    return 0;
}
