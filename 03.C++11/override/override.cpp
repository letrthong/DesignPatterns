// Example program
#include <iostream>
#include <string>
using namespace std;

 
class A
{
public:
    A(){}
    ~A(){}
	
	virtual  void func()
	{
		std::cout<<"A func "<< std::endl;
	}

private:
     
    
};


class B : public  A
{

public: 
	void func() override 
	{
		std::cout<<" B func "<< std::endl;
	}
};





int main()
{
 
  A* p = new B;
  
  p->func();
 
  return 0;
}
