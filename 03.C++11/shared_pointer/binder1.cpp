/*
*  C++ 11
*
*
*/

// C++ code to demonstrate bind() and 
// placeholders 
#include <iostream> 
#include <functional> // for bind() 
using namespace std; 
  
// for placeholders 
using namespace std::placeholders; 
  
// Driver function to demonstrate bind() 

class B{
    public: 
    void func(int a, int b, int c) 
    { 
        cout<<"a="<<a<<endl;
        cout<<"b="<<b<<endl;
        cout<<"c="<<c<<endl;
        _number = _number +1;
         cout<<"number="<<_number<<endl;
    } 
  
    private :
    int  _number = 0;
};

int main() 
{ 
    // for placeholders 
    using namespace std::placeholders; 
   B object;
    
    auto fn1 =  bind( &B::func, &object, _1,  _2, _3 ); 
  
    
    fn1(3,5,7);
  
    fn1(10,6,8);
    return 0; 
} 
