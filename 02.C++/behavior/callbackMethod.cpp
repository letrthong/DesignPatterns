#include <iostream>

using namespace std;

typedef  int  (*callback)(int , int);


class A
{
public:

    static int sum(int a , int b )
    {
        return (a+b);
    }
    
    int callFuntion(int a, int b, callback fun)
    {
        return fun(a,b);
    }
    
private:

};


class B
{
  public:
    
    B()
    {
        int ret =a.callFuntion(1,2, B::sub);
         cout<<"sub="<< ret<<endl;
        
    }
    
    static int sub(int a , int b )
    {
       
        return (a-b);
    }
    
  
  
  private:
  
  A  a;
  
};

int main()
{
    
    B b;
  
   return 0;
}

////https://developer.gnome.org/glib/stable/glib-Singly-Linked-Lists.html#g-slist-foreach
//sub=-1
