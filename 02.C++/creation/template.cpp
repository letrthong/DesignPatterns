#include <iostream>
#include <vector>

using namespace std;

template <class T>


class Stack
{
public:
	void push(T val);
	T pop();
	bool isEmpty();
private:
	std::vector<T> mStack;
};

template <class T>

void Stack<T>::push(T val)
{
    
}

template <class T>
T  Stack<T>::pop()
{
    T t;
    return t;
}

template <class T>
bool  Stack<T>::isEmpty()
{
    return true;
}


int main()
{
   Stack<int> stack;
   stack.push(8);
   stack.pop();
   
   return 0;
}
