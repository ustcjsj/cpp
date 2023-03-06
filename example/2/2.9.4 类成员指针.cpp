#include <iostream> 
using namespace std; 
struct Point
{ 		int x, y;
		Point(int a, int b)   { x=a; y=b;}
		void MovePoint( int a, int b)  { x+=a; y+=b;}
		void print()  { cout<<"x="<<x<< '\t'<<"y="<<y<<endl;}
};
int main() 
{	
	//指向类数据成员的指针
	int Point::*p=&Point::x;
	Point  point1(1,2);   //定义对象
	Point  *point2=new Point(3,4);    //类point的对象指针
	cout<<point1.*p<<endl;   	//输出：1
	p=&Point::y;          //指向新的数据成员
	cout<<point1.*p<<endl;   	//输出：2
	point2->*p=5;         //置point2.y=5
	cout<<point2->x<<endl; 	//输出：3
	cout<<point2->y<<endl; 	//输出：5

	//指向类成员函数的指针
	void ( Point::*pf) (int,int);     //定义类成员函数指针pf
	pf=&Point::MovePoint;       //函数指针指向MovePoint()
	(point1.*pf)(10,10);             //相当于point1.MovePoint(10,10);
	point1.print();	                //输出x=11 y=12 
}

