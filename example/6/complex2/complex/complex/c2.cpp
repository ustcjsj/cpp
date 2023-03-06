#include <iostream>
using namespace std;
#include "Complex2.h"
int c2()
{	Complex2  c1(7.7,5.5 );
	Complex2  c2( 4.2, -8.3 );
	Complex2  c3;

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
	c3 =10+c1+5 ;  //ok
	//6.5 输入输出操作符的重载:例6-12 
	cout<<"10+ (";
	cout<<c1;
	cout<< ") + 5 = "<<c3<<'\n' ;

	return  0;
}
