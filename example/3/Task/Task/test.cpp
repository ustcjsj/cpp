#include "Task.h" //*** Task class
#include <iostream>
using namespace std;
int main() {
time_t now = time( 0 );
Task t1("Defrost pizzas"),
	t2( "Open beer" ),
	t3( "Eat pizzas and drink beer" );
t1.setST( now ); 
t1.setFT( now + 3600 ); // an hour from now
t2.setST( t1.getFT() ); // when pizzas defrosted
t2.setFT( t2.getST() + 2 ); // fast work
t3.setST( t2.getFT() + 1 ); // slight delay
t3.setFT( t3.getST() + 7200 ); // leisure meal
//t3.logToFile();
return 0;
}
