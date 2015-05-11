#include <iostream>
#include <cstdlib>
using namespace std;


class Car
{

private:
	float a;
	int b;
	int c;
	string d;
	
public:
	float GetA()
	{
		return a;
	}
	
	void SetA(int nA)
	{
		a = nA;
	}
	
	Car()
	{
		a = 50;
		b = 30;
		c = 4;
		d = "adr";
	}
	
	Car(float inputa,int inputb,int inputc,string inputd)
	{
		a = inputa;
		b = inputb;
		c = inputc;
		d = inputd;
	} 
};

int main()
{	
	Car n[3] = {Car(123,456,789,"adr1") , Car(10,11,12,"adr2"), Car(11,23,55,"adr3")};


	system("pause");
	return 0;
}

