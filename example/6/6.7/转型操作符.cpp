#include<iostream>
using namespace std;
class counter
{  public:                               
       counter() 
	   {	iVal=0; }               //ȱʡ���캯��
       counter( int  v) { iVal=v; }      //����ת�����캯��
       ~counter(){ }
       operator  unsigned short()         //����ת����Ա����
		 {   return static_cast<unsigned  short>(iVal);        //���� ת�� ���͵Ķ���
        }
  private: 
       int iVal;
 };
void main()
{   counter  x(3);            
	unsigned short  a;
    a=x;  //����ֵ���ұߵ�����ת��Ϊ��ߵ����� 
             //����x����ʽת��Ϊunsigned short����
    x=x+a;                //���ܳ��ֶ�����,��øĳ�: x=x+counter(a)

	cout<<x<<endl;  //��������ת����Ա����������
}
