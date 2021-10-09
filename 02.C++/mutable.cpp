//https://www.tutorialspoint.com/cplusplus-mutable-keyword
#include <iostream>
using namespace std;
code
class Test {
   public:
      int a;
   mutable int b;
   Test(int x=0, int y=0) {
      a=x;
      b=y;
   }
   void seta(int x=0) {
      a = x;
   }
   void setb(int y=0) {
      b = y;
   }
   void disp() {
      cout<<endl<<"a: "<<a<<" b: "<<b<<endl;
   }
};
int main() {
   const Test t(10,20);
   cout<<t.a<<" "<<t.b<<"\n";
   // t.a=30; //Error occurs because a can not be changed, because object is constant.
   t.b=100; //b still can be changed, because b is mutable.
   cout<<t.a<<" "<<t.b<<"\n";
   return 0;
}