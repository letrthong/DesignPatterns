/*
*
*FileName: abstract.cpp
*Author  : ThongLT
*Compile : g++ abstract.cpp -o abstract
*
*/
    
#include <iostream>
using namespace std;

class FlyBehavior
{
public:
    virtual void fly() = 0;
};

class FlyWithWings : public FlyBehavior
{
public: 
      void fly()
      {
          cout<<"I can fly "<<endl;
      }
};

class FlyNoWay : public FlyBehavior
{
public: 
      void fly()
      {
          cout<<"I can not fly "<<endl;
      }
};


class QuackBehavior{
public:
     virtual void quack() = 0;
};


class Quack :public QuackBehavior
{
public :
     void quack()
     {
         cout<<"I can quack"<<endl;
     }
};

class Duck
{
public:
    void swim()
    {
       cout<<"I can swim "<<endl;
    }
    
    void setFlyBehavior(FlyBehavior *flyBehavior)
    {
        pFlyBehavior =  flyBehavior;
    }
    
    void setQuackBehavior(QuackBehavior *quackBehavior)
    {
        pQuackBehavior =  quackBehavior;
    }
    
    void perfromFly()
    {
       pFlyBehavior->fly();
    }
    
    void perfromQuack()
    {
         pQuackBehavior->quack();
    }
    
    virtual void display()=0;
    
    Duck()
    {  
         cout<<"Duck"<<endl;
        pQuackBehavior = NULL;
        pFlyBehavior =NULL;
    }
    
     ~Duck()
    {  
         cout<<"~Duck"<<endl;
        if(pQuackBehavior)
        {
             delete pQuackBehavior;
             pQuackBehavior = NULL;
        }
       
        if(pFlyBehavior)
        {
            delete pFlyBehavior;
            pFlyBehavior =NULL;
        }
    }
private:
    QuackBehavior *pQuackBehavior;
    FlyBehavior *pFlyBehavior;
};


class RedheadDuck: public Duck
{
 public:
    void display()
    {
         cout<< "I am RedheadDuck"<<endl;
    }
};

int main()
{
    Duck *ptr= new RedheadDuck();
    if(ptr == NULL)
    {
        return 0;
    }
    
    ptr->setFlyBehavior(new FlyWithWings());
        
    ptr->display();
    ptr->swim();
    ptr->perfromFly();
    
    delete ptr;
    ptr = NULL;
    return 0;
}


