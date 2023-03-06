#include <iostream>
#include <string>
using namespace std;
class CNameList
{ public:
	CNameList(void) : size(0), p(0) {};
	CNameList(const string [], int);
	CNameList(const CNameList&);
	//CNameList& operator= (const CNameList&);
    ~CNameList(void);
	void set(const string& s, int i) { p[i] = s; }
	void set(const char* s, int i) { p[i] = s; }
	void dump() const;
private:
	int size;
	string* p;
	void copyIntoP(const CNameList&);
};

CNameList::~CNameList(void) { }

CNameList::CNameList(const string s[], int si)
{	p = new string[size = si];
	for (int i=0; i<size; i++)
		p[i] = s[i];
}

CNameList::CNameList(const CNameList& d) : p(0)
{	copyIntoP(d);  }

//CNameList& CNameList::operator= (const CNameList& d)
//{	if (this != &d)
//		copyIntoP(d);
//	return *this;
//}

void  CNameList::dump() const {
	for (int i=0; i<size; i++)
		cout<<p[i]<<'\t';
	cout<<endl;
}

void  CNameList::copyIntoP(const CNameList& d) {
	delete [] p;
	if (d.p != 0) {
		p = new string[size = d.size];
		for (int i=0; i<size; i++)
			p[i] = d.p[i];	}
	else	{
		p = 0;
		size = 0;	}
}
int main()
{	string list[] = {"Lab","Zhihua","Song"};
	CNameList d1(list, 3);
	d1.dump();
	CNameList d2;	//=n1; 这样是调拷贝构造函数
	d2= d1;
	d2.dump();
	d2.set("Great Dane", 1);
	d2.dump();
	d1.dump();
	return  0;
}
