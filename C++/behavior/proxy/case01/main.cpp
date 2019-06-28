#include <iostream>

using namespace std; 

class Subject 
{
public:
	virtual void request() = 0;
	virtual ~Subject() {}
};
 
class RealSubject : public Subject 
{
public:
	void request() { 
		cout << "RealSubject.request()" << endl; 
	}
};
 
class Proxy : public Subject 
{
private:
	Subject* realSubject;
public:
	Proxy() : realSubject (new RealSubject()) 
	{}
	~Proxy() { 
		delete realSubject; 
	}
	// Forward calls to the RealSubject:
	void request() { 
		realSubject->request(); 
	}
};
 
int main() {
	Proxy p;
	p.request();
}


//https://www.bogotobogo.com/DesignPatterns/proxy.php