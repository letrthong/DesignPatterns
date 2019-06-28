#include <iostream>

using namespace std; 

class Subject 
{
public:
	virtual void request() = 0;
	virtual ~Subject() {}
};
 
class RealSubject01 : public Subject 
{
public:
	void request() { 
		cout << "RealSubject01.request()" << endl; 
	}
};
 
class RealSubject02 : public Subject 
{
public:
	void request() { 
		cout << "RealSubject02.request()" << endl; 
	}
};


class Proxy : public Subject 
{
private:
	Subject* realSubject;
public:
	Proxy(int id)  
	{
	    if(id == 0)
	    {
	         realSubject= new RealSubject01;
	    }
	    else
	    {
	        realSubject= new RealSubject02;
	    }
	 }
	~Proxy() { 
		delete realSubject; 
	}
	// Forward calls to the RealSubject:
	void request() { 
		realSubject->request(); 
	}
};
 
int main() {
	Proxy p(1);
	p.request();
}


//https://www.bogotobogo.com/DesignPatterns/proxy.php