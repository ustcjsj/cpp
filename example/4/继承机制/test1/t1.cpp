#include <iostream>
#include <string>
using namespace std;
class Location {
	public:
		void InitL( int xx, int yy );
		void Move( int xOff, int yOff );
		int GetX( ) { return X; }
		int GetY( ) { return Y; }
	private:
		int X, Y;   
};
void Location::InitL( int xx ,int yy ) 
{	X = xx; 	Y = yy; }
void Location::Move( int xOff, int yOff ) 
{	X += xOff;	Y += yOff;     }

class Rectangle : private Location	{
	public:
		void InitR( int x, int y, int w, int h );
		int GetH( ) { return H; }
		int GetW( ) { return W; }
	private:
		int W, H;
};
void Rectangle::InitR( int x, int y, int w, int h ) {
	InitL( x, y );	W = w;	H = h;
}

// 私有继承
class Rectangle2 : private Location	{
	public:
		void InitR(int x, int y, int w, int h );
		void Move(int xOff, int yOff );
		int GetX( ) { return Location::GetX(); }
		int GetY( ) { return Location::GetY(); }
		int GetH( ) { return H; }
		int GetW( ) { return W; }
	private:
		int W, H;  
};
void Rectangle2::InitR( int x, int y, int w, int h ) {
	InitL( x, y );
	W = w;
	H = h;
}
void Rectangle2:: Move( int xOff, int yOff ) {
	Location::Move(xOff, yOff );
}



int main()
{	
	Rectangle2 rect;  //Rectangle2 rect;
    rect.InitR( 2, 3, 20, 10 ); // 间接调用基类的方法
    rect.Move( 3, 2 );	   // 调用基类中声明的方法
    cout << rect.GetX() << ',' << rect.GetY() << ','
            << rect.GetW() << ',' << rect.GetH() << endl;
    return 0;

}