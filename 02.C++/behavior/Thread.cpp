

#include <iostream>
using namespace  std;
#include <pthread.h>

typedef void*  (*start_routine)(void *);

class Thread
{
 public: 
	Thread()
	{
		cout << "Thread()" << endl;
	}
	
	~Thread()
	{
		cout << "~Thread()" << endl;
	}
	
	void run(start_routine callback )
	{
		int ret = pthread_create(&_id, NULL, callback, NULL);
		if ( ret != 0)
		{
			//Error
		}
	}
	
	void join()
	{
		pthread_join( _id, NULL);
	}
	
 private: 
	pthread_t _id;
};
/*
*http://www.polarsparc.com/pdf/PThreads.pdf
*/


class A
{
public: 
	void start()
	{
		_thread.run(exec);
	}
private :
    static void* exec(void *arg)
    {
		cout<<"ThongLT"<<endl;
		return (void *)0;;
	}
	 
private:
	Thread _thread;
};


int main()
{
	A a;
	a.start();
	int i=0;
	while(true)
	{	
		cout<<"\n i=";
		cin>>i;
		if(i == 0)
		{
			
		}
		else  if( i == 1)
		{
		}
		
	}
	return 0;
}

//g++ main.cpp -lpthread
