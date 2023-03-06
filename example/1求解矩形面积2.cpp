#include <iostream>
using namespace std;
class Rectangle
{  public:
	void SetData(float L,float W)   //输入长、宽值
		{	if (L>0.0) length=L; else length=0.0;
			if (W>0) width=W; else width=0; 
	   }
       float CompueterArea()   //计算面积
		{   area=0;
			if (length>0 && width>0)
				area=length*width;	
			return area; 
	   }
       float CompueterGirth()   //计算周长
		{   girth=0;
			if (length>0 && width>0)
				girth=length+width+length+width;
			return girth;
		}
       void OutputArea()    //输出面积
		{	cout<<"Area="<<area<<endl; }
       void OutputGirth()    //输出周长
		{	cout<<"Girth="<<girth<<endl;}
	private: 
	   float length,width,area,girth; //定义长、宽、面积、周长
}; 
int main()
{	Rectangle  Rectangl;   //声明对象
	Rectangl.SetData(8,9); //
    Rectangl.CompueterArea();
    Rectangl.CompueterGirth();
    Rectangl.OutputArea();
    Rectangl.OutputGirth();
	return 0;
}