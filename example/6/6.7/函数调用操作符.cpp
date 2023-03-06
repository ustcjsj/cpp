#include <iostream>
using namespace std;
class  F
{   public :
       double  operator()(double x,double y) const
		 {    return    x*2+y;  }
 };
void main()
 {  F  f;
    cout<<f(1.5,3.2)<<endl;    // f.operator()(1.5,3.2) 
 }
