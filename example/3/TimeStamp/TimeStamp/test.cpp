#include "TimeStamp.h"
#include <iostream>
using namespace std;
void dumpTS( const TimeStamp& );
int main() {
	TimeStamp ts;	
	time_t now = time(0);
	ts.set();	dumpTS( ts );

	ts.set( now + 200000 );	dumpTS( ts );

	ts.set( now - 300000 );	dumpTS( ts );

	ts.set( -999 );	dumpTS( ts );

	return 0; 
}
void dumpTS( const TimeStamp& ts ) {
	cout <<"\nTesting methods:\n";
	cout <<'\t'<< ts.get() << endl;
	cout <<'\t'<< ts.getAsString() << endl;
	cout <<'\t'<< ts.getYear() << endl;
	cout <<'\t'<< ts.getMonth() << endl;
	cout <<'\t'<< ts.getDay() << endl;
	cout <<'\t'<< ts.getHour() << endl;
	cout <<'\t'<< ts.getMinute() << endl;
	cout <<'\t'<< ts.getSecond() << endl;
}
