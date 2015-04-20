#include <iostream>
#include <cstdlib>
using namespace std;
/*
1.請設計一個用以描述汽車的類別，包含以下成員變數：
  a.油箱大小
  b.平均每公升汽油行進距離
  c.載客數
  d.車牌號碼

2.請設計對應各成員變數的成員函數
  a.建構子
  b.存取與修改成員變數的成員函數
  c.計算可行進距離的成員函數

3.請分別收集3輛汽車的資料，以可行進距離大小排列，輸出三輛汽車資料
*/
class RunRunCaDingCar
{
	private:
		int _tank_net,_foot_long,_people_count_max;
		string _car_id;
	public:
		void SetAllProperties(int TankNET,int FootLong,int PeopleCountMax,string ID)
		{
			_tank_net = TankNET ,_foot_long = FootLong, _people_count_max = PeopleCountMax ,_car_id = ID;
		}
		RunRunCaDingCar(int TankNET,int FootLong,int PeopleCountMax,string ID){SetAllProperties(TankNET , FootLong, PeopleCountMax , ID);}
		RunRunCaDingCar() {SetAllProperties(-1 , -1, -1, "");}
		/*SET TANK NET*/
		void SetTankNET(int NET) {_tank_net = NET;}
		int GetTankNET() {return _tank_net;}
		/*SET FOOT LONG*/
		void SetFootLong(int Long) {_foot_long = Long;}
		int GetFootLong() {return _foot_long;}
		/*SET PEOPLE COUNT MAX*/
		void SetPeopleCount(int Count) {_people_count_max = Count;}
		int GetPeopleCount() {return _people_count_max;}
		/*SET CAR ID*/
		void SetCarID(string NewID) {_car_id = NewID;}
		string GetCarID() {return _car_id;}
		/*Func*/
		int HowLongICanGo(){return ( (_tank_net < 1) || (_foot_long < 1) ? 0 :_tank_net*_foot_long);}
		void PrintProperties() 
		{ 
			cout <<"車號 "<< _car_id << " 油箱容量:" << _tank_net ;
			cout << ", 每公升可跑" << _foot_long << "公里 ,可載" << _people_count_max << "人,";
			cout << "可行車距離"<< HowLongICanGo() <<"\n";
		}
};

void SwapCar(RunRunCaDingCar &Car1, RunRunCaDingCar &Car2)
{
	RunRunCaDingCar *Car0 = new RunRunCaDingCar(Car1.GetTankNET(),Car1.GetFootLong(),Car1.GetPeopleCount(),Car1.GetCarID());
	Car1.SetAllProperties(Car2.GetTankNET(),Car2.GetFootLong(),Car2.GetPeopleCount(),Car2.GetCarID());
	Car2.SetAllProperties(Car0->GetTankNET(),Car0->GetFootLong(),Car0->GetPeopleCount(),Car0->GetCarID());
}

int main()
{
	RunRunCaDingCar n[3] = {RunRunCaDingCar(5,6,7,"8"),RunRunCaDingCar(1,2,3,"4"),RunRunCaDingCar(9,10,11,"12")};
	cout << "原始資料：\n";
	for(int i(0); i < 3; n[i].PrintProperties(),i++);
	cout << "\n依照可行進距離大小排序後：\n";
	for(int i(0); i < 3; i++) for(int j(i); j < 3; j++) if (n[i].HowLongICanGo() > n[j].HowLongICanGo()) SwapCar(n[j],n[i]);
	for(int i(0); i < 3; n[i].PrintProperties(),i++);
	system("PAUSE");
	return 0;
}
