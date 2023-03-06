#include <iostream>
using namespace std;
class  String
{  private:
     char *sPtr;
     int  length;
   public:
	 void myout() {cout<<sPtr<<endl;}
     String(const char* s);              //类型转换构造函数
	 //const String& operator=(const String& right);
     ~String();                          //析构函数
};
String::String(const char* s)
{  cout<<"类型转换构造函数called"<<endl;
   length = strlen(s);                      //计算字符串长度
   sPtr = new char[length+1];             //分配内存
   //assert(sPtr!=NULL);                      //当内存分配失败时终止
   strcpy(sPtr,s);                          //把字符串直接拷贝到对象中
}
const String& String::operator=(const String& right)
{  cout<<"operator =()called"<<endl;
   if(this != &right )                             //避免自我赋值
	{  delete[]  sPtr;                      //防止内存漏洞
       length=right.length;                 //取新字符串长度
	   sPtr=new char[length+1];             //分配内存
	   //assert(sPtr!=NULL);             	  //保证分配了内存
	   for (int i=0;i<length;i++)
		   sPtr[i]=right.sPtr[i];
       //strcpy(sPtr,right);             //拷贝字符串    
   }
   else       cout<<"Attempted assignment of a String to itself\n";
    return   *this ;                          //保证能够连续赋值
}

String::~String()
{  delete[]  sPtr;               	    //收回为对象分配的内存
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
