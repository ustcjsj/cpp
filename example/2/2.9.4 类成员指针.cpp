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
	//ָ�������ݳ�Ա��ָ��
	int Point::*p=&Point::x;
	Point  point1(1,2);   //�������
	Point  *point2=new Point(3,4);    //��point�Ķ���ָ��
	cout<<point1.*p<<endl;   	//�����1
	p=&Point::y;          //ָ���µ����ݳ�Ա
	cout<<point1.*p<<endl;   	//�����2
	point2->*p=5;         //��point2.y=5
	cout<<point2->x<<endl; 	//�����3
	cout<<point2->y<<endl; 	//�����5

	//ָ�����Ա������ָ��
	void ( Point::*pf) (int,int);     //�������Ա����ָ��pf
	pf=&Point::MovePoint;       //����ָ��ָ��MovePoint()
	(point1.*pf)(10,10);             //�൱��point1.MovePoint(10,10);
	point1.print();	                //���x=11 y=12 
}

