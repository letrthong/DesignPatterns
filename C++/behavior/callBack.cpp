
#include <iostream>
using namespace std;

class A0
{
public:
	virtual void callback() = 0;
};

class C
{
public:
	C()
	{
		cout<<"C: constructor"<<endl;
	}
	
	~C()
	{
		cout<<"C: destructor"<<endl;
	}
	
	void setA0(A0* pA0)
	{
		_pA0 = pA0;
	}
	
	void tostring()
	{
		cout<<"C: tostring"<<endl;
		_pA0->callback();
	}

private:
   A0* _pA0;
   
};


class A1 : public A0, public C
{
public:
	A1()
	{
		cout<<"A1: constructor"<<endl;
		C::setA0(this);
	}
	 
	virtual ~A1()
	{
		cout<<"A1: destructor"<<endl;
	}
	
	int sendMessage()
	{
		C::tostring();
	}
	
    virtual void callback()
	{
		cout<<"A1: callback"<<endl;
	};
};

class A2 : public A1
{
	public:
	
	A2()
	{
		cout<<"A2: constructor"<<endl;
	}
	
	~A2()
	{
		cout<<"A2: destructor"<<endl;
	}
	
	void callback()
	{
		cout<<"A2: callback"<<endl;
	}
	
};

int main()
{
	A1* p = new A2;
	p->sendMessage();
	delete p;
	
	return 0;
}

/*
C: constructor
A1: constructor
A2: constructor
C: tostring
A2: callback
A2: destructor
A1: destructor
C: destructor
*/
