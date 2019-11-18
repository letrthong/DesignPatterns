#include <iostream>
using namespace std;

class Beverage{
public:
    virtual  int cost() = 0;
};


class HouseBlend :public Beverage
{
public:
     int cost()
     {
         return 1;
     }
};



class DarkRoast :public Beverage
{
public:
     int cost()
     {
         return 2;
     }
};


class Decaf :public Beverage
{
public:
     int cost()
     {
         return 3;
     }
};


int main()
{
    int cost = 0;
    Beverage  *p = new HouseBlend();
    cost = p->cost();
    delete p;
    
    p = new DarkRoast();
    cost += p->cost();
    cout<<"cost="<< cost<<endl;
    delete p;
    return 0;
}

