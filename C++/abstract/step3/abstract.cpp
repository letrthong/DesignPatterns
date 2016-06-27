/*
*
*FileName: abstract.cpp
*Author  : ThongLT
*Compile : g++ abstract.cpp -o abstract
*
*/
    
#include <iostream>
using namespace std;

class Duck
{
public:
    
    virtual void quack()
    {
        cout<<"I can quack"<<endl;
    }
    
    void swim()
    {
       cout<<"I can swim "<<endl;
    }
    
    virtual void fly(){
        cout<<"I can fly "<<endl;
    }
    virtual void display() = 0;
};


class DallorDuck  :public  Duck
{
public:
    void display()
    {
        cout<< "I am DallorDuck"<<endl;
    }
};

class RedheadDuck: public Duck
{
    void display()
    {
         cout<< "I am RedheadDuck"<<endl;
    }
};

class RubberDuck: public Duck
{
    void display()
    {
         cout<< "I am RubberDuck"<<endl;
    }
    
    void fly(){
        cout<<"I can not fly "<<endl;
    }
    
    void quack()
    {
        cout<<"I can not quack"<<endl;
    }
};



int main()
{
    Duck *ptr= new RubberDuck();
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


