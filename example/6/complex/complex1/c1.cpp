#include <iostream>
using namespace std;
#include "Complex.h"

	int main()
	{	Complex  c1(7.7,5.5 );
		Complex  c2( 4.2, -8.3 );
		Complex  c3;

		c3 = c1 + c2;
		cout<< "c1 + c2 = ";
		c3.write();
		cout<< '\n' ;

		c3 = c1 - c2;
		cout<< "c1 - c2 = ";
		c3.write();	cout<< '\n' ;

		c3 = c1 * c2;
		cout<< "c1 * c2 = ";
		c3.write();	cout<< '\n' ;

		c3 = c1 / c2;
		cout<< "c1 / c2 = ";
		c3.write();	cout<< '\n' ;
		return  0;
	}