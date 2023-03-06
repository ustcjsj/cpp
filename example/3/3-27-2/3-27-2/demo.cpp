#include <iostream>
using namespace std;
class C {
public:
	C() { cout <<"Default constructor"<< endl;  num = 0; }
	void set( int n ) { num = n; }
	int  get() const { return num; } 	
	C( const C& c ) { //3.5.6中 修改成 private
		cout <<"Copy constructor"<< endl;  num = c.num;
	}
private:
	int  num; 
};
void f(C c) {  //3.5.6中 修改成 C& c
	cout <<"entering f(C)"<<'\t';
	c.set( -999 );
	cout << "c: " << c.get() <<'\t'<<"leaving f(C)"<< endl;
}
C g() //3.5.6中 修改成 C &g()
{	cout <<"entering g()"<< endl;
	static C c3;  //3.5.6中 修改成 static 
	cout << "c3: " << c3.get() << '\n';
	c3.set( 123 );
	cout << "c3: " << c3.get() << '\t'<<"leaving g()"<< endl;
	return c3;  //copy
}
int main() {
	C c1, c2;
	cout << "c1: " << c1.get() << '\t';
	cout << "c2: " << c2.get() << endl;
	f( c1 );  //copy c1
	cout << "c1: " << c1.get() << endl;
	c2 = g();
	cout << "c2: " << c2.get() << endl;
	return 0;
}
