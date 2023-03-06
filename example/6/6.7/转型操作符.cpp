#include<iostream>
using namespace std;
class counter
{  public:                               
       counter() 
	   {	iVal=0; }               //缺省构造函数
       counter( int  v) { iVal=v; }      //类型转换构造函数
       ~counter(){ }
       operator  unsigned short()         //类型转换成员函数
		 {   return static_cast<unsigned  short>(iVal);        //返回 转换 类型的对象
        }
  private: 
       int iVal;
 };
void main()
{   counter  x(3);            
	unsigned short  a;
    a=x;  //将赋值号右边的类型转换为左边的类型 
             //即将x隐形式转换为unsigned short类型
    x=x+a;                //可能出现二义性,最好改成: x=x+counter(a)

	cout<<x<<endl;  //如无类型转换成员函数，出错
}
