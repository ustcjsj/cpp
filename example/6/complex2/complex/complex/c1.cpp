#include <iostream>
using namespace std;
#include "Complex.h"
int c1()
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
	
	c3 =c1+5 ;  //ok
	cout<<"(";	c1.write(); cout<< ") + 5 = "; 
	c3.write();	cout<< '\n' ;
	//c3=5+c1; //Error
	return  0;
}
