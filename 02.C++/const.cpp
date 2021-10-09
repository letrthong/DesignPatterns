// https://stackoverflow.com/questions/8716330/purpose-of-returning-by-const-value
#include <iostream>
using namespace  std;


class A
{
public:
    A():member_()
    {
    }

    int hashGetter() const
    {
        state_ = 1;
        return member_;
    }
    
    int goodGetter() const
    {
        return member_;
    }
    
    int getter() const
    {
        // member_ = 2; // error
        
        return member_;
    }
    
    int badGetter()
    {
        return member_;
    }
private:
    mutable int state_;
    int member_;
};



int main()
{
     const A a1;
    a1.badGetter(); // doesn't work
    a1.goodGetter(); // works
    a1.hashGetter(); // works

    A a2;
    a2.badGetter(); // works
    a2.goodGetter(); // works
    a2.hashGetter(); // works
     
     return 0;
}