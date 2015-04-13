/*
請參考第一次小考的設定，設計以下程式功能：
1.設計適當結構儲存所有資料(編號、性別、身高、體重、BMI)
2.設計適當程式完成BMI的計算
3.設計適當程式讀取檔案資料到結構中
4.設計適當程式顯示所有資料
*/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
using namespace std;
struct Profile
{
	string ID;
	bool Sex;
	float Kg;
	float Height;
	float BMI;
};
int main()
{
	fstream fileInput;
	fileInput.open("data.txt",ios::in);
	if (!fileInput) exit(0);
	
	Profile UserList[100] = Profile();
	float KgRecord(0),HeightRecord(0),MaxBMI(0);
	int pos(0),MaleCount(0),MaxHeightPos(0);
	
	for(; pos < 100 ; pos++)
	{
		if (!(fileInput >> UserList[pos].ID >> UserList[pos].Sex >> UserList[pos].Kg >> UserList[pos].Height)) break;
		UserList[pos].BMI = UserList[pos].Kg *100 *100/ (UserList[pos].Height * UserList[pos].Height);
		KgRecord += UserList[pos].Kg; 
		HeightRecord += UserList[pos].Height;
		MaxBMI =  (UserList[pos].BMI > MaxBMI ? UserList[pos].BMI : MaxBMI);
		MaxHeightPos = (UserList[pos].Height > UserList[MaxHeightPos].Height ? pos : MaxHeightPos);
		MaleCount += UserList[pos].Sex;
	}
	cout << "平均身高:" << (HeightRecord/(pos)) << ", 平均體重:" << (KgRecord/(pos)) << endl;
	cout << "最大BMI:" << MaxBMI << ", 最高者的編號:" << UserList[MaxHeightPos].ID << endl;
	cout << "男女人數比 " << MaleCount << ":" << (pos - MaleCount) <<endl;
	fileInput.close();
	system("PAUSE");
	return 0;
}

