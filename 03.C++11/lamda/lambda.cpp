//https://www.tutorialspoint.com/compile_cpp11_online.php
// https://docs.microsoft.com/en-us/cpp/cpp/lambda-expression-syntax?view=msvc-160

#include <iostream>
using namespace  std;


void (*callback)(int); 

void real_function(int x) {
    cout<<"hello world x="<< x <<endl;
    
}

int main()
{
     callback = &real_function;
     callback(3);
    
    
     callback  = [](int x){  
         
         cout<<"lambda hello world x="<< x<<endl;
     };
     
     callback(3);
}