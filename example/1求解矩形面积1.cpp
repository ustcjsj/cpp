#include <iostream>
using  namespace std;
float Area(float l,float w)  {	return l*w;}
float Girth(float l,float w)  {	return l+l+w+w;}
int  main()
{	float length,width,area,girth;    //定义变量长、宽、面积
	length=8;    width=9; //长、宽值
	area=Area(length,width);      //计算面积
	girth=Girth(length,width);      //计算周长
    cout<<"Area:"<<area<<",\tGirth:"<<girth<<endl;     //输出面积
	return 0;
}