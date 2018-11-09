// statemachine.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class BaseRoot
{
public:
	virtual void  goBack() = 0;
	virtual void createObject() = 0;
	virtual void deleteObject() = 0;
};

class  ChilBase
{
public:
	virtual ~ChilBase() {};
};

class ChildA : public ChilBase
{
public:
	 ChildA()
	{
	}

	ChildA(BaseRoot* pBaseRoot)
	{
		cout << "ChildB->BaseRoot" << endl;
		_pBaseRoot = pBaseRoot;
		waitCli();
	}

	~ChildA()
	{
		cout << "Destructor" << endl;
	}

	void waitCli()
	{
		int  back = false;
		int  cli = 0;
		while (back == false)
		{
			cout << "\nChildA::cli= ?  ";
			cin >> cli;

			switch (cli)
			{
			case 0:
				back = true;
				break;
			default:
				break;
			}
		}
	}
private:
	BaseRoot* _pBaseRoot;

};

class ChildB :public ChilBase
{
public:
	ChildB(BaseRoot* pBaseRoot)
	{
		cout << "ChildB->BaseRoot" << endl;
		_pBaseRoot = pBaseRoot;
		waitCli();
	}

	~ChildB()
	{
		cout << "Destructor" << endl;
	}

	void waitCli()
	{
		int  back = false;
		int  cli = 0;
		while (back == false)
		{
			cout << "\nChildB::cli= ?  ";
			cin >> cli;

			switch (cli)
			{
			case 0:
				back = true;
				break;
			default:
				break;
			}
		}
	}
private:
	BaseRoot* _pBaseRoot;

};


class Root : public BaseRoot {

public:

	Root()
	{
		_pChild = NULL;
	}

	void  goBack()
	{
	}

	void createObject()
	{
		int  cli = 0;

		
		cout << "\nRoot::cli= ?  ";
		cin >> cli;
		if (cli == 1)
		{
			_pChild = new ChildA(this);
		}
		else if(cli == 2)
		{
			_pChild = new ChildB(this);
		}
	    else
		{
			exit(0);
		}
	}

	void deleteObject()
	{
		cout << "Root::delete object" << endl;
		delete _pChild;
		_pChild = NULL;
	}
private:
	ChilBase* _pChild;
};


int main()
{
	Root root;
	while (true)
	{
		root.createObject();
		root.deleteObject();
	}
	
    return 0;
}

