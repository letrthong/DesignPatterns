#include <iostream>
using namespace std;

class Beverage{
private :
     int mCost;
public:
     Beverage()
     {
         mCost = 0;
     }
     virtual int cost()
     {
         return mCost;
     }
    
    void setHouseblend(Beverage *beverage)
    {
        mCost = mCost + beverage->cost();
    }
    
    void setDarkRoast(Beverage *beverage)
    {
        mCost = mCost + beverage->cost();
    }
    
     void setDecaf(Beverage beverage)
    {
        mCost = mCost + beverage.cost();
    }
};


class HouseBlend :public Beverage
{
public:
     ~HouseBlend()
     {
         cout<<"~HouseBlend()"<<endl;
     }
    
     int cost()
     {  
         return  1;
     }
};
 
class DarkRoast :public Beverage
{
public:
     ~DarkRoast()
     {
        cout<<"~DarkRoast()"<<endl;
     }
    
     int cost()
     {
         return 3;
     }
};


class Decaf :public Beverage
{
public:
     ~Decaf()
     {
         cout<<"~Decaf()"<<endl;
     }
    
     int cost()
     {
         return  5;
     }
};

int main()
{
    Beverage beverage;
    beverage.setHouseblend(new HouseBlend());
    beverage.setHouseblend(new DarkRoast());
    beverage.setDecaf(Decaf());
    
    cout<<beverage.cost()<<endl;
    //@Todo : memory leak
    return 0;
}

