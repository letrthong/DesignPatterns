/*
*  C++ 11
*
*
*/

#include <iostream>
#include  <memory>
//for more C++ tutorial visit www.ProDeveloperTutorial.com
using namespace std;

class MyClass
{
  
  public:
  MyClass()
  {
      cout<<"In constructor"<<endl;
  }
  
  void show(){
     cout<<"show"<<endl;
  }
  ~MyClass()
  {
      cout<<"In destructor"<<endl;
  }
  
  
};


int main() 
{ 
     cout<<"main start"<<endl;
    unique_ptr<MyClass> p (new MyClass);
    p->show();
    
    unique_ptr<MyClass>  p1 = make_unique<MyClass> ();
    
    MyClass* p2= p.get();
    p2->show();
    
    delete p2;   
    
    cout<<"main end"<<endl;
    return 0; 
} 
