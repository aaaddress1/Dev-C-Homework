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

