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
    void quack()
    {
        cout<<" I can quack"<<endl;
    }
    
    void swim()
    {
       cout<<"I can swim "<<endl;
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
 
int main()
{
    Duck *ptr= new DallorDuck();
    if(ptr == NULL)
    {
        return 0;
    }
    
    ptr->display();
    ptr->swim();
    
    delete ptr;
    ptr = NULL;
    return 0;
}


