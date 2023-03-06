#include <iostream>
using namespace std;
template <typename T>//函数模板
T max1(T a, T b)  { cout<<"call template:"; return a>b? a:b;}
int max1(int a,float b)  // 用普通函数重载函数模板
 { cout<<"call func:"; return a>b? a:b;}

char* max1(char* a,char* b)//重载函数
{  cout<<"call func2:"; return strcmp(a,b)>0? a:b;}

int main( )
{	char a='4',b='5';    int c=5;
	cout << max1(a,b) << endl;
    cout << max1(a,c) << endl;
	char *p,*h;  p="abc"; h="ef";  
	cout<< max1(p,h) << endl; //重载函数
	return 0;
}
