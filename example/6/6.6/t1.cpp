#include <iostream>
using namespace std;
class  String
{  private:
     char *sPtr;
     int  length;
   public:
	 void myout() {cout<<sPtr<<endl;}
     String(const char* s);              //����ת�����캯��
	 //const String& operator=(const String& right);
     ~String();                          //��������
};
String::String(const char* s)
{  cout<<"����ת�����캯��called"<<endl;
   length = strlen(s);                      //�����ַ�������
   sPtr = new char[length+1];             //�����ڴ�
   //assert(sPtr!=NULL);                      //���ڴ����ʧ��ʱ��ֹ
   strcpy(sPtr,s);                          //���ַ���ֱ�ӿ�����������
}
const String& String::operator=(const String& right)
{  cout<<"operator =()called"<<endl;
   if(this != &right )                             //�������Ҹ�ֵ
	{  delete[]  sPtr;                      //��ֹ�ڴ�©��
       length=right.length;                 //ȡ���ַ�������
	   sPtr=new char[length+1];             //�����ڴ�
	   //assert(sPtr!=NULL);             	  //��֤�������ڴ�
	   for (int i=0;i<length;i++)
		   sPtr[i]=right.sPtr[i];
       //strcpy(sPtr,right);             //�����ַ���    
   }
   else       cout<<"Attempted assignment of a String to itself\n";
    return   *this ;                          //��֤�ܹ�������ֵ
}

String::~String()
{  delete[]  sPtr;               	    //�ջ�Ϊ���������ڴ�
}

void fun(String &aa)
{   cout<<"Enter fun\n";  
	String  c("789");
    c = aa;
	cout<<"Leave fun\n";
}

void main()
{   cout<<"qwe\n";
	String a("12345"),b("xyz");
    b=a;
    /*fun(a);
	a.myout();
    a = a;
	a.myout();
	*/
}
