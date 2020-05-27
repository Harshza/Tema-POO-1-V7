#include "Stiva_pereche.h"
#include "SimulareStiva.h"

Pereche make_pereche(const int &a,const int &b){
    Pereche p(a,b);
    return p;
} //nush de ce,dar daca functia asta nu era pusa in main,imi dadea ca nu e definita,am cautat pe stack
//si am vazut ca ar fi trb sa-i fac un intreg header si cpp separat

int main()
{
    Multime_pereche M;
    std::cin >> M;
    M.pop(make_pereche(2, 0));
    std::cout << M << '\n';
    Stiva_pereche stk;
    stk.push(make_pereche(0, 0));
    stk.push(make_pereche(3, 5));
    stk.push(make_pereche(0, 0));
    stk.push(make_pereche(0, 1));
    stk.push(make_pereche(1, 0));
    std::cout << stk << '\n';
    stk.pop();
    stk.pop();
    std::cout << stk << '\n';
    stk.clear();
    std::cout << stk << '\n';
    stk.pop();
    stk.push(make_pereche(5, 3));
    stk.push(make_pereche(7, 9));
    stk.push(make_pereche(9, 13));
    std::cout << stk << '\n' << M << '\n';
    std::cin >> stk;
    std::cout << stk << '\n';
    Coada_pereche Q;
    Q.push(make_pereche(2,0));
    Q.push(make_pereche(0,3));
    Q.push(make_pereche(2,2));
    Q.push(make_pereche(-1,2));
    std::cout << Q << '\n';
    Pereche x = Q.pop();
    std::cout << Q << '\n' << x << '\n';
    Stiva_pereche stk2;
    stk2 = stk; //operatorul egal este mostenit din multime(si pentru coada)
    std::cout << stk2 << '\n';
    SimulareStiva stk3;
    stk3.push(make_pereche(3, 5));
    stk3.push(make_pereche(-7, 10));
    stk3.push(make_pereche(1, 9));
    std::cout << stk3.pop() << '\n';
    stk3.push(make_pereche(3, 5));
    stk3.push(make_pereche(4, 4));
    std::cout << stk3 << '\n';
    std::cin >> stk3;
    std::cout << stk3 << '\n';
    return 0;
}
