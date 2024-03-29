#include <iostream>

using namespace std;

class Base
{ 
public:
    Base(){
        cout << "Base Constructor Called\n";
    }
    virtual ~Base(){
        cout << "Base Destructor called\n";
    }
};

class Base1
{ 
public:
    Base1(){
        cout << "Base1 Constructor Called\n";
    }
    virtual ~Base1(){
        cout << "Base1 Destructor called\n";
    }
};


class Derived1: public Base, Base1
{
public:
    Derived1(){
        cout << "Derived constructor called\n";
    }
    virtual ~Derived1(){
        cout << "Derived destructor called\n";
    }
};

int main()
{
    Base *b = new Derived1();
    delete b;
}
