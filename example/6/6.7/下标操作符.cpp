#include <iostream>
using namespace std;
class  CharArray
{  public:
	   CharArray(int len);
     	~CharArray();
       char & operator[](int i);
       int getlength() const{ return  length; }
    private:
       int  length;
       char  *buff;    };
CharArray::CharArray(int len)
{   length=len;
     buff=new char[length];  }
CharArray::~CharArray()   {    delete[]  buff;   	}
char& CharArray::operator[](int i)
{   static char  ch=0;
    if(i>=0 && i<length)       return   buff[i];
    else
    {	cout<<"\nIndex out of range.\n";
		return  ch;    }        
}
void main()
{  int j;
   CharArray string1(6);
   char *string2="abcdefg";
   for(j=0;j<7;j++)   string1[j]=string2[j];  // string2[6]±£´æÔÚch
   for(j=0;j<7;j++)  cout<<string1[j];
   cout<<"\nlength:"<<string1.getlength()<<endl;
 }
