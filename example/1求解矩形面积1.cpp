#include <iostream>
using  namespace std;
float Area(float l,float w)  {	return l*w;}
float Girth(float l,float w)  {	return l+l+w+w;}
int  main()
{	float length,width,area,girth;    //����������������
	length=8;    width=9; //������ֵ
	area=Area(length,width);      //�������
	girth=Girth(length,width);      //�����ܳ�
    cout<<"Area:"<<area<<",\tGirth:"<<girth<<endl;     //������
	return 0;
}