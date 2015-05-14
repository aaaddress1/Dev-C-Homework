#include <iostream>
using namespace std;
#define HourSec (60*60)
#define MinSec  (60)
/*
1.請設計一個描述時間的類別MyTime
   成員變數：時hour、分min、秒sec
   建構子與成員函數

2.請重新定義cin、cout與Mytime的導向運算

3.請重新定義MyTime的加法運算

4.請使用MyTime設計一個程式，可輸入兩個時間，輸出兩個時間相加的總和
Hint：請注意進位60sec=1min, 60min=1hour
*/
class MyTime
{
	private:
	int Hour,Min,Sec;
	public:
	void FixCurrentTime()
	{
		int SecondSum = Hour * HourSec + Min * MinSec + Sec;
		Hour = SecondSum / HourSec;
		SecondSum -= Hour * HourSec;
		Min = SecondSum / MinSec;
		SecondSum -= Min * MinSec;
		Sec = SecondSum;
	}
	
	MyTime(int NewHour,int NewMin,int NewSec) { Hour = NewHour,Min = NewMin,Sec = NewSec;FixCurrentTime();}
	MyTime() { MyTime( 0, 0, 0);}
	int GetHour() { return Hour;}
	int GetMin()  { return Min;}
	int GetSec()  { return Sec;}
	void SetHour(int NewHour) { Hour = NewHour;}
	void SetMin(int NewMin) { Min = NewMin;}
	void SetSec(int NewSec) { Sec = NewSec;}
	
	friend ostream& operator<< (ostream& out,MyTime d) 
	{
		out << d.Hour << " Hour " <<d.Min<<" Minute "<<d.Sec << " Second";      
		return out;
	}  
	friend istream& operator>> (istream& in,MyTime& d)
	{
		in >> d.Hour >> d.Min >> d.Sec;      
		return in;
	}

	friend MyTime operator+ (MyTime a,MyTime b)
	{
	   int Data[3] ={  a.GetHour() + b.GetHour() , 
					   a.GetMin()  + b.GetMin()  ,
					   a.GetSec()  + b.GetSec() };
	   return MyTime(Data[0],Data[1],Data[2]);
	}
};

int main() 
{
	MyTime n[2] ;
	cout << "請輸入第一筆時間之 小時 分鐘 秒數: " ; 
	cin >> n[0];
	cout << "請輸入第二筆時間之 小時 分鐘 秒數: " ; 
	cin >> n[1];
	cout << n[0]+n[1] ;
	return 0;
}
