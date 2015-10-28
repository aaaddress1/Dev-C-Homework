/**
*隨機產生100名學生之國文、英文、數學、自然、社會五科會考成績，單
*科成績>=90分其等級為A，小於90但>=80為B，小於80但>=70為C，小於70
*但>=60為D，小於60為F。M大多於(包含)2個F即不錄取，K大平均>=60即錄
*取，哪一校錄取比較多人?最後產生下列表格
**/
#include<iostream>
#include <stdio.h>
#include <ctime>
using namespace std;
char Level(int score)
{
	// 100 ~ 90 = A = 0x41
	// 90  ~ 80 = B = 0x42 = 0x41 + 1
	// 80  ~ 70 = C = 0x43 = 0x42 + 2
	// 70  ~ 60 = D = 0x44 = 0x43 + 3
	// 60 down  = E = 0x45 = 0x44 + 4
		 if (score <	60)	return 'F';
	else if (score >=	100)return 'A';
	return (char)('A' + (3-((score - 60)/10)));
}

int main()
{
	int array[100][5];
	srand(time(NULL));
	for (int i = 0; i < 100; ++i)
		for (int j = 0; j < 5; array[i][j] = (rand() % 100) + 1,++j);
    
	cout << "姓名\t國文\t等級\t英文\t等級\t數學\t等級\t自然\t等級\t社會\t等級\t平均\tM大錄取\tK大錄取\n";
	int SumM(0),SumK(0);
    for (int i(0),M(0),sum(0); i < 100; ++i)
	{
		M = 0;
		sum = 0;
		cout << "A" << i << "\t";
		for (int j(0); j < 5; ++j)
		{
            sum += array[i][j];
			char levelTemp = Level(array[i][j]);
			M += (levelTemp == 'F');
			cout << array[i][j] << "\t" << levelTemp << "\t" ;
		}
		SumM += (M < 2);
		SumK += (sum >= 300);
		cout << (sum/5) << "\t" << (M > 1?"否":"是") << "\t" <<(sum >= 300? "是":"否") << "\n";
	}
	cout << "M大錄取了:\t" << SumM << "\n";
    cout << "K大錄取了:\t" << SumK << "\n";
    if (SumM == SumK) cout << "兩大學錄取一樣多人\n"; 
    else cout << (SumM > SumK? "M":"K") << "大錄取較多人\n"; 
    system("PAUSE");
	return 0 ;
}
