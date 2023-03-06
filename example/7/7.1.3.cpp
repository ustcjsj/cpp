#include <iostream>
using namespace std;

template<class  T, int a>
class C {
	T x;
  public:
	C() { cout<<"1:";x=a; }
	C(T xx) { cout<<"2:"<<a<<",";  x=xx; }
	T getX()  { return x; }
 };

int main()
{	C<double,8>  a1( 10 );
	cout<<a1.getX()<<endl;

	C<double,5>  a2;
	cout<<a2.getX()<<endl;
	return 0;
}
