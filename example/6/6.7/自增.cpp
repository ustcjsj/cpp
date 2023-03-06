#include<iostream>
using namespace std;
class Clock	 
{ public:	
	  Clock(int hour=0, int minute=0, int second=0)
		{  m_nHour=hour; m_nMinute= minute; m_nSecond=second; }
	  Clock  operator ++();     //ǰ�õ�Ŀ���������
	  Clock operator ++(int);  //���õ�Ŀ���������
private:	
	  int m_nHour, m_nMinute, m_nSecond;

	friend ostream& operator<<(ostream&,Clock);
};

Clock Clock::operator++()	//ǰ�õ�Ŀ��������غ���
{	m_nSecond++;
	if (m_nSecond >= 60)
	{    m_nSecond = m_nSecond-60;
	     m_nMinute++;
	     if(m_nMinute >= 60)
	     {    m_nMinute = m_nMinute-60;
	          m_nHour++;
	          m_nHour = m_nHour%24;
	     }
	}
    return *this;
}

//���õ�Ŀ��������أ�ע���βα��е����Ͳ���
Clock Clock::operator ++(int)	
{	Clock old=*this;
   ++(*this);
   return old;
}

ostream& operator<<(ostream& out,Clock c)
{	return  out << c.m_nHour << ":" << c.m_nMinute
              <<":"<<c.m_nSecond;
}

int main()
{	Clock myClock(23,59,59);
	cout<<"First time output: "<<myClock<<endl;

   cout<<"\nShow myClock++\nBefore++: "<<myClock++;
	cout<<"\tAfter++: "<<myClock<<endl;

   cout<<"\nShow ++myClock: "<<++myClock<<endl;

   return 0;
}
