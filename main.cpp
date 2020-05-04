#include <iostream>
#include "Pereche.h"
#include "Multime_pereche.h"
#include "Stiva_pereche.h"
#include "Coada_pereche.h"

using namespace std;

int main()
{
    Stiva_pereche stk;
    Coada_pereche Q;
    cin >> stk >> Q;
    cout << stk << '\n' << Q;
    return 0;
}
