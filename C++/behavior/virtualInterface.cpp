

#include <iostream>
using namespace std;


class  A
{
public: 
	A()
	{
		cout<<"A::Constructor "<<endl;
	}
	virtual ~A()
	{
		 cout<<"A::Destructor"<<endl;
	}
	virtual  void   display() = 0;
};

class C  
{
	public:
	 C(A *a)
	 {
		pA = a; 
		cout<<"C::Constructor "<<endl;
	 }
	 
	 ~C()
	 {
		 cout<<"C::Destructor "<<endl;
	 }
	 
	 int processC()
	 {
		 pA->display();
	 }
	private :
	
	A* pA;
	
};

class B : public virtual A
{
	public :
	B()
	{
		cout<<"B::Constructor "<<endl;
	}
	
	~B()
	{
		cout<<"B::Destructor "<<endl;
	}
	 void   display()
	 {
		 cout<<"hello world"<<endl;
	 }
	
};


int main ()
{
	
    A *b = new B;
	 
	 C  *c = new  C(b);
	 
	c->processC();
	
	delete c;
	delete b;
	
	return 0;
}
