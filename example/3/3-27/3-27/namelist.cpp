#include <iostream>
#include <string>
using namespace std;
class Namelist {
	public:
		Namelist()  { size=0;  p=0;  }
		Namelist( const string [ ], int );
		Namelist( const Namelist& d ); //拷贝构造函数
		void set( const string&, int );
		void set( const char*, int );
		void dump() const;
	private:
		int size;
		string* p;
		void copyIntoP( const Namelist& d );
};
Namelist::Namelist( const string s[ ], int si ) {
	p = new string[ size = si ];
	for ( int i = 0; i < size; i++ )
		p[ i ] = s[ i ];    
}
void Namelist::set( const string& s, int i ) {
	p[ i ] = s;   
}
void Namelist::set( const char* s, int i ) {
	p[ i ] = s;   
}
void Namelist::dump() const {
	for ( int i = 0; i < size; i++ )
		cout << p[ i ] << '\t';
	cout<<endl;
}
 //拷贝构造函数
Namelist::Namelist( const Namelist& d )  {
	p=0;   copyIntoP( d );    
}
void Namelist::copyIntoP( const Namelist& d ) {
	delete[ ] p;
	if ( d.p != 0 ) {
		p = new string[ size = d.size ];
		for ( int i = 0; i < size; i++ )
			p[ i ] = d.p[ i ];}
		else {	p = 0;  size = 0;}
}

int main() {
string list[ ] = { "111", "222", "333" };
Namelist d1( list, 3 );   d1.dump(); // 111, 222, 333
Namelist d2( d1 );       d2.dump(); // 111, 222, 333
d2.set( "aaa", 1 );
d2.dump(); // 111, aaa, 333
d1.dump(); // ***** Caution: 111, aaa, 333
return 0;
}
