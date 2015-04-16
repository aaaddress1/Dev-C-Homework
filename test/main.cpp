#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;


struct date1
{
   string id;
   bool sex;
   float weight;
   float height;
   float BMI;
};


int main()
{	
	ifstream fin("data.txt");    
	
	date1 my_data;
	int boy = 0;
	int girl = 0;
	
  	cout << "編碼:   性別:   體重:   身高:   BMI:" << endl; 
	while (fin>>my_data.id >> my_data.sex >> my_data.weight >> my_data.height)
	{
		
		my_data.BMI = 10000*my_data.weight/my_data.height/my_data.height;
		if (my_data.sex) 
		{
			boy++;	
			cout << my_data.id << "\t男\t"<< my_data.weight << "\t" << my_data.height <<"\t" << my_data.BMI <<"\n";

		}
		else
		{
			girl++;
			cout << my_data.id << "\t女\t"<< my_data.weight << "\t" << my_data.height <<"\t" << my_data.BMI <<"\n";
		}
	    
    }
	fin.close();
	system("pause");
	return 0;
}

