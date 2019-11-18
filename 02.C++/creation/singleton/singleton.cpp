#include <iostream>
using namespace std;

class Single
{

public : 

	Single()
	{
		m_singleton = NULL;
	}
	static  Single *getSingle()
	{   
		if (m_singleton == NULL)
		{
			m_singleton = new Single;
		}
		return m_singleton;
	}

	void discription()
	{
		cout<<" singleton in design patterns " <<endl;
	}

private :

	static Single *m_singleton ;    
};


Single *Single::m_singleton  = NULL; 

int main()
{
	Single::getSingle()->discription();
	return 1;
}