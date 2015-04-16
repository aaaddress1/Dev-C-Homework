#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
using namespace std;
/*
請參考第一次小考的設定，設計以下程式功能：

1.設計適當結構儲存所有資料(編號、性別、身高、體重、BMI)
2.設計適當程式完成BMI的計算
3.設計適當程式讀取檔案資料到結構中
4.設計適當程式顯示所有資料
*/
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
	for(int pos(0); ( pos < 100 )&&(fileInput >> UserList[pos].ID >> UserList[pos].Sex >> UserList[pos].Kg >> UserList[pos].Height) ; pos++)
	{
		UserList[pos].BMI = UserList[pos].Kg *100 *100/ (UserList[pos].Height * UserList[pos].Height);
		cout << "[" << (pos + 1) << "]\t" << UserList[pos].ID << "\t" << (UserList[pos].Sex ? "男":"女");
		cout << "\t身高:" << UserList[pos].Height << "\t體重:" << UserList[pos].Kg << "\tBMI:" << UserList[pos].BMI <<endl;
	}
	fileInput.close();
	system("PAUSE");
	return 0;
}

