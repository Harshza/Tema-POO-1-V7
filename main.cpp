#include <iostream>
#include <list>

using namespace std;

#include "Pesti.h"
#include "Nevertebrate.h"

list<Animal*> L;

int main()
{
    Animal *p = new Peste();
    auto ob = dynamic_cast<Peste*>(p);
    cin >> *ob;
    cout << *ob;
    return 0;
}
