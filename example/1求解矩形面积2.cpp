#include <iostream>
using namespace std;
class Rectangle
{  public:
	void SetData(float L,float W)   //���볤����ֵ
		{	if (L>0.0) length=L; else length=0.0;
			if (W>0) width=W; else width=0; 
	   }
       float CompueterArea()   //�������
		{   area=0;
			if (length>0 && width>0)
				area=length*width;	
			return area; 
	   }
       float CompueterGirth()   //�����ܳ�
		{   girth=0;
			if (length>0 && width>0)
				girth=length+width+length+width;
			return girth;
		}
       void OutputArea()    //������
		{	cout<<"Area="<<area<<endl; }
       void OutputGirth()    //����ܳ�
		{	cout<<"Girth="<<girth<<endl;}
	private: 
	   float length,width,area,girth; //���峤����������ܳ�
}; 
int main()
{	Rectangle  Rectangl;   //��������
	Rectangl.SetData(8,9); //
    Rectangl.CompueterArea();
    Rectangl.CompueterGirth();
    Rectangl.OutputArea();
    Rectangl.OutputGirth();
	return 0;
}