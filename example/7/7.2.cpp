#include <iostream>
#include <string>
//#define NDEBUG //**** enable/disable assertions
#include <cassert>
using namespace std;

template< class T >
class Stack {
public:
   enum { DefaultStack = 50, EmptyStack = -1 };
   Stack();
   Stack( int );
  ~Stack();
   void push( const T& );
   T pop();
   T topNoPop() const;
   bool empty() const;
   bool full() const;
private:
   T* elements;
   int top;
   int size;
   void allocate()  { elements = new T[ size ];  top = EmptyStack;   } 
   void msg( const char* m ) const  {
       cout << "*** " << m << " ***" << endl;   }
   friend ostream& operator<<( ostream&, const Stack< T >& );
};

template< class T >
Stack<T>::Stack() {  size = DefaultStack;   allocate(); }

template< class T >
Stack<T>::Stack( int s ) {
   if ( s < 0 )       // negative size?
     s *= -1;
   else if ( 0 == s ) // zero size?
     s = DefaultStack;
   size = s;
   allocate();
}
template< class T >
Stack< T >::~Stack()  { delete[ ] elements;  }

template< class T >
void Stack<T>::push( const T& e ) {
   assert( !full() );
   if ( !full() )
     elements[ ++top ] = e;
   else
     msg( "Stack full!" );
}
template< class T >
T Stack< T >::pop() {
   assert( !empty() );
   if ( !empty() )
     return elements[ top-- ];
   else {
     msg( "Stack empty!" );
     T dummy_value=0;
     return dummy_value; // return arbitrary value   w:使用了未初始化的局部变量
   }
}
template< class T >
T Stack< T >::topNoPop() const {
   assert( top > EmptyStack );
   if ( !empty() )
     return elements[ top ];
   else {
     msg( "Stack empty!" );
     T dummy_value;
     return dummy_value;
   }
}
template< class T >
bool Stack< T >::empty() const {  return top <= EmptyStack;  }

template< class T >
bool Stack< T >::full() const {   return top + 1 >= size; }

template< class T >
ostream& operator<<( ostream& os, const Stack<T>& s ) {
   s.msg( "Stack contents:" );
   int t = s.top;
   while ( t > s.EmptyStack )  cout << s.elements[ t-- ] << endl;
   return os;   
}

int main(){
	const string prompt = "Enter an algebraic expression: ";
	const char lParen = '(';
	const char rParen = ')';
	Stack< char >  s;
	string buf;
	cout<< prompt << endl;
    getline( cin, buf );
	for ( int i = 0; i < static_cast<int>(buf.length()); i++)
	{  if ( !isspace( buf[i] )  )  s.push( buf[i] );   } 
	cout<< "Original expression:  "  <<buf   <<endl;
	cout<< "Expression in reverse:  ";
	while  (!s.empty())	
	{	char  t = s.pop();
	if (t == lParen)  t = rParen;  else if (t == rParen)  t = lParen;
	cout<<t;  }
cout<<endl;
return 0;


 //Stack<int> s;
 //int i;
 //for(i=15;i<30;i++){
 // s.push(i);
 //}

 //while(!s.empty()){
 // cout<<s.pop()<<endl;
 //}
 //Stack<float> sf;
 //for(i=1;i<10;i++){
 // float t=1.0/i;
 // sf.push(t);
 //}
 //cout<<sf.topNoPop();
 //sf.pop();
 //cout<<sf.topNoPop()<<endl;
 //while(!sf.empty()) cout<<sf.pop()<<endl;

}