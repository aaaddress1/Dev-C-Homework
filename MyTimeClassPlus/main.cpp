#include <iostream>
using namespace std;
#define HourSec (60*60)
#define MinSec  (60)

class MyTime
{
	private:
	int Hour,Min,Sec;
	
	public:
	int CurrentAllSec() { return (Hour * HourSec + Min * MinSec + Sec);}
	MyTime(int NewHour,int NewMin,int NewSec) { Hour = NewHour,Min = NewMin,Sec = NewSec;FixCurrentTime();}
	MyTime() { MyTime( 0, 0, 0);}
	
	void FixCurrentTime()
	{
		int SecondSum = CurrentAllSec();
		Hour = SecondSum / HourSec;
		SecondSum -= Hour * HourSec;
		Min = SecondSum / MinSec;
		SecondSum -= Min * MinSec;
		Sec = SecondSum;
	}
	
	int GetHour() { return Hour;}
	int GetMin()  { return Min;}
	int GetSec()  { return Sec;}
	void SetHour(int NewHour) { Hour = NewHour;}
	void SetMin(int NewMin) { Min = NewMin;}
	void SetSec(int NewSec) { Sec = NewSec;}
	friend bool operator> (MyTime a,MyTime b){ return a.CurrentAllSec() > b.CurrentAllSec();}
	friend bool operator< (MyTime a,MyTime b){ return a.CurrentAllSec() < b.CurrentAllSec();}
	friend bool operator== (MyTime a,MyTime b){ return a.CurrentAllSec() == b.CurrentAllSec();}
	friend bool operator!= (MyTime a,MyTime b){ return a.CurrentAllSec() != b.CurrentAllSec();}
	friend MyTime operator+ (MyTime a,MyTime b){ return MyTime( 0, 0, a.CurrentAllSec() + b.CurrentAllSec());}
	friend MyTime operator- (MyTime a,MyTime b){ return MyTime( 0, 0, a.CurrentAllSec() - b.CurrentAllSec());}
	friend MyTime operator* (MyTime a,int b){ return MyTime( 0,0, a.CurrentAllSec() * b);}
	friend MyTime operator/ (MyTime a,int b){ return MyTime( 0,0, a.CurrentAllSec() / b);}
	friend float operator/ (MyTime a,MyTime b){ return ((float)a.CurrentAllSec() / (float)b.CurrentAllSec());}
		
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
};

int main() 
{
	MyTime n[2] = {};
	int Times(0);
	
	cout << "請輸入第一筆時間之 小時 分鐘 秒數: " ; 
	cin >> n[0];
	cout << "請輸入第二筆時間之 小時 分鐘 秒數: " ; 
	cin >> n[1];
	
	if (n[0] == n[1]) cout << "兩筆時間一樣長\n";
	else cout << (n[0] > n[1] ? "第一筆時間" : "第二筆") << "時間較長\n"; 
	
	cout << "兩筆時間間隔：\t" << (n[0] > n[1] ? n[0] - n[1] : n[1] - n[0]) << endl; 
	cout << "兩筆時間總和：\t" << n[0] + n[1] << endl; 
	cout << "第一筆與第二筆時間的時間長度比例為：\t" << (n[0] / n[1])<< endl; 
	
	cout << "請輸入一個倍數：";cin >> Times;
	cout << "第一筆時間乘上" << Times << "倍後為：\t" << n[0] * Times << endl; 
	cout << "第二筆時間乘上" << Times << "倍後為：\t" << n[1] * Times << endl; 	
	return 0;
}
