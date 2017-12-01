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
    virtual void  callA() = 0;
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


    void callC()
    {
        cout<<"C::callC "<<endl;


        pA->callA();
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

        pC = new C(this);
    }

    ~B()
    {
        delete pC;
        cout<<"B::Destructor "<<endl;
    }

    void  callA()
    {
        cout<<"B::callA"<<endl;
    }

    void   display()
    {
        cout<<"B::hello world"<<endl;

        pC->callC();
    }

private :
    C* pC ;

};

int main ()
{

    A *b = new B;
    b->display();
    delete b;

    return 0;
}
