#include <iostream>
using namespace std;
#include "Stack.h"
int main() {
	Stack s1;
	//s1.init();
	s1.push( 9 );	
	s1.push( 4 );  //ѹջ
	s1.dump();	// ��ջ����ջ�����ջԪ�أ�4 9
	cout <<"Popping "<< s1.pop() << endl;
	s1.dump();	// 9
	s1.push( 8 );
	s1.dump();	// 8 9
	s1.pop();    
	s1.pop();
	s1.dump();	// empty
	s1.pop();		// still empty
	s1.dump();	// ditto
	s1.push( 3 );
	s1.push( 5 );
	s1.dump();	// 5 3
	for( unsigned i=0; i<Stack::MAX_STACK; i++ )
		s1.push( 1 );
	s1.dump(); 	// 1 1 1 5 3
	return 0;
}