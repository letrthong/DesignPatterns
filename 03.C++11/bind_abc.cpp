#include <bits/stdc++.h>
using namespace std;
// function which has to be binded.
int add(int a, int b) { return a + b; }
  
int main()
{
    auto addf = bind(add, 10, 20);
    // binding the Function add() to values 10 and 20.
    cout << "The output is " << addf() << endl;
    // the Functor addf is called.
    return 0;
}
