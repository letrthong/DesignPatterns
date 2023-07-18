#include <bits/stdc++.h>
using namespace std;
#include <iostream>

using namespace std;

// function which has to be binded.
int add(int a, int b) { return a + b; }
 
 class  A{
    public:
     int sum(int a, int b) { 
         cout <<"A::sum a=" << a <<" b= " << b << " -> " << a + b;
         return a + b; 
         
     }
     
 };
int main()
{
    auto addf = bind(add, 10, 20);
    // binding the Function add() to values 10 and 20.
    cout << "The output is " << addf() << endl;
    // the Functor addf is called.
    
    A a;
    
    auto ptr_to_print_sum = std::mem_fn(&A::sum);
    auto f4 = std::bind(ptr_to_print_sum, & a, 95,1);
    
    
    
    f4();
    
    return 0;
}
// https://en.cppreference.com/w/cpp/utility/functional/bind
