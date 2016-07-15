/**
*Compile: g++ multithreading.cpp *.h  Thread.cpp Mutex.cpp -lpthread
*Author : ThongLT
**/
#include <iostream>
using namespace std;

#include "Thread.h"
#include "Mutex.h"
    
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

class Singleton
{
public : 
	static  Singleton *getObject()
	{   
        //If two threads are making this test at the same time
        Mutex lock(&m_Mutex);
		if (m_pObject == NULL)
		{
			m_pObject = new Singleton;
            cout<<"Create object"<<endl;
		}
        
		return m_pObject;
	}
    
    void detroyObject()
    {
        if(m_pObject)
        {
            delete m_pObject;
            m_pObject = NULL;
        }
    }
    
    void setNumber(int number)
    {
        m_Number = number;
    }
    
	int getNumber()
	{
		return m_Number;
	}

private :
   // Make constructor and destructor private. 
    Singleton()
	{
        cout<<"constructor"<<endl;
        m_pObject = NULL;
        m_Number = 0;
	}
    
    ~Singleton()
    {
         cout<<"destructor"<<endl;
    }
    
	static Singleton *m_pObject ;
    static pthread_mutex_t m_Mutex;
    
    int m_Number;
};

//static members
Singleton *Singleton::m_pObject = NULL;     
pthread_mutex_t Singleton::m_Mutex;


class MyThread : public Thread
{
    public:
    void *run() {
        for (int i = 0; i < 10; i++) {
            printf("thread %lu running - %d\n",  (long unsigned int)self(), i);
            Singleton::getObject()->setNumber(i);
            usleep(100);
            cout<<Singleton::getObject()->getNumber()<<endl;
          
        }
        printf("thread done %lu\n", (long unsigned int)self());
        return NULL;
    }
};

int main()
{
    MyThread* thread1 = new MyThread();
    MyThread* thread2 = new MyThread();
    thread1->start();
    thread2->start();
    thread1->join();
    thread2->join();
    printf("main done\n");
    
    Singleton::getObject()->detroyObject();
	return 0;
}