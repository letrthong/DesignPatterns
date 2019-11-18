#include <iostream>
using namespace std;

#include <vector>

class A;

typedef  vector<A*>::iterator  AIter;
typedef  vector<A*>  AVector;
class A
{
public:
    A() {}

    virtual ~A() {}

    virtual void show()
    {
        cout<<"A::show"<<endl;
    }
	
    static void  callbackSignal()
    {
        cout<<"A::callbackSignal"<<endl;
        AIter cii;
        for(cii= list.begin(); cii!= list.end(); cii++)
        {
            (*cii)->show() ;
        }
    }

protected:
    static void  register_callback( class A* pA)
    {
        if(pA)
        {
            list.push_back(pA);
        }
    }

    static void  unregister_callback( class A* pA)
    {
        if(pA)
        {
            for( AIter iter = list.begin(); iter != list.end(); ++iter )
            {
                if( *iter == pA )
                {
                    list.erase( iter );
                    break;
                }
            }
        }
    }

protected:
    static  AVector list;
};

AVector A::list;

class B : public A
{
public:
    B()
    {
        register_callback(this);
    }

    virtual ~B()
    {
        unregister_callback(this);
    }

    virtual void show()
    {
        cout<<"B::show"<<endl;
    }
};

class C : public A
{
public:
    C()
    {
        register_callback(this);
    }

    virtual ~C()
    {
        unregister_callback(this);
    }
};

int main ()
{

    B *pB = new B();
    C  c;
    A::callbackSignal();
    delete  pB;

    A::callbackSignal();
    return 0;
}
