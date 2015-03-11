#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
int total_money = 0;
void SetTotalMoney(bool Paid,int Money)
{
	total_money = total_money + Money * (Paid? -1 : 1);
}

void ChkMoneySum()
{
	system("cls");
	fstream fileInput;
	fileInput.open("data.txt",ios::in);
	if (!fileInput) return;
	int Type(0),Money(0);
	char result[256];
	total_money = 0;
	while(fileInput >> Type>> Money >> result)
	{
		cout << (Type?"[支出]\t":"[收入]\t") << Money << "元\t原因: " << result << endl;
		SetTotalMoney(Type,Money);
	}
	fileInput.close();
	cout << "目前您的總金額為: " << total_money << endl << endl;
}

int main()
{
	ChkMoneySum();
	fstream fileOutput;
	fileOutput.open("data.txt",ios::out|ios::app);
	if (!fileOutput)
	{
		cout << "cannot open file.";exit(0);
	}
	char result[256] = {};
	for(int choise(-1),Money(0);;)
	{
		cout << "請輸入您想記錄:[0]收入 [1]支出 [2]離開? ";cin >> choise;
		if ( choise > 2 || choise < 0 ) continue;
		else if (choise == 2) break;
		cout << "請輸入您的金額: ";cin >> Money;
		if ( Money < 1 ) continue;
		cout << "請輸入此筆記錄的理由(最多256字元,不得有空白): ";cin >> result;
		fileOutput << choise << " " << Money << " "<< result << endl;
		SetTotalMoney(choise,Money);
		ChkMoneySum();
	}
	fileOutput.close();
	return 0;
}
