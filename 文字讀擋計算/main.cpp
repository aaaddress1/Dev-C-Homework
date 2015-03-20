#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
/*
1.讀取一個文字檔案
2.計算此文字檔案中有多少個大寫字元
3.計算此文字檔案中有多少個小寫字元
4.計算次文字檔案中有多少個數字字元
5.計算次文字檔案中有多少個符號字元
5.計算次文字檔案中有多少個單字
*/
bool IsNumber(char i)
{
	return ((i > 47) && (i < 58));
}
bool IsUppercase(char i)
{
	return ((i > 64) && (i < 91));
}
bool IsLowercase(char i)
{
	return ((i > 96) && (i < 123));
}
bool IsSymbol(char i)
{
	return ((i > 31) && (i < 127)) && (!IsNumber(i)) && (!IsUppercase(i)) && (!IsLowercase(i));
}
int main()
{
	fstream fileInput;
	fileInput.open("data.txt",ios::in);
	if (!fileInput) exit(0);
	int NumberCount(0),UpperCount(0),LowerCount(0),Symbol(0),WordCount(1);
	cout << "檔案內文字: ";
	for(char current_char;fileInput.get(current_char);)
	{
		NumberCount += IsNumber(current_char);
		UpperCount += IsUppercase(current_char);
		LowerCount += IsLowercase(current_char);
		Symbol += IsSymbol(current_char);
		WordCount += (!(current_char - 32));
		cout <<current_char;
	}
	cout << "\n\n發現了一共 " << NumberCount << "個數字, " <<  UpperCount << "個大寫字, " ;
	cout << LowerCount << "個小寫字, " << Symbol << "個符號,共" << WordCount << "個單字.\n"; 
	fileInput.close();
	system("pause");
	return 0;
}

