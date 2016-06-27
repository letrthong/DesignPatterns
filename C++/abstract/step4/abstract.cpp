/*
*
*FileName: abstract.cpp
*Author  : ThongLT
*Compile : g++ abstract.cpp -o abstract
*
*/
    
#include <iostream>
using namespace std;

class Flyable
{
public:
    virtual void fly() = 0;
};

class Quackable{
public:
     virtual void quack() = 0;
};

class Duck
{
public:
    void swim()
    {
       cout<<"I can swim "<<endl;
    }
 
    virtual void display()=0;
};


class RedheadDuck: public Duck,public virtual  Flyable, public virtual  Quackable
{
 public:
    void display()
    {
         cout<< "I am RedheadDuck"<<endl;
    }
    
    void fly()
    {
           cout<< "I can fly"<<endl;
    }
    
    void quack()
    {
            cout<< "I can quack"<<endl;
    }
};

int main()
{
    RedheadDuck *ptr= new RedheadDuck();
    if(ptr == NULL)
    {
        return 0;
    }
    
    ptr->display();
    ptr->swim();
    ptr->fly();
    
    delete ptr;
    ptr = NULL;
    return 0;
}


