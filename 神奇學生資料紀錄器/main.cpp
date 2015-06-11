#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
using namespace std;

/*
1.請設計一個基礎類別Person，來紀錄一個人的姓名與年齡
2.請設計一個基礎類別Course，來記錄一個科目的期中考與期末考成績
3.請設計一個繼承基礎類別Person與基礎類別Course的衍生類別Student，來紀錄一個學生的姓名、年齡、學號、年級與成績
4.請使用類別Student，讀取檔案record，將所有學生以平均分數高低排序後輸出

PS：請自行設計所有類別所需的成員變數、成員函數、建構子與運算子重載*/
class Person
{
	public:
		string Name;
		int Old;
		Person(string nName,int nOld){Name = nName, Old = nOld;}
		Person(){Name = "null", Old = 0;}
};

class Course
{
	public:
		float MidExam;
		float FinalExam;
		float Average;
		float GetAvg(){ Average = (MidExam+FinalExam)/2;}
		Course(float nMidExam,float nFinalExam){ MidExam = nMidExam, FinalExam = nFinalExam,GetAvg();}
		Course(){ MidExam = 0,FinalExam = 0,Average = 0;}
};

class Student: public Course,public Person
{
	public:
		string SID;
		int SGrade;
		Student(string nName,int nOld,string nSID,int nSGrade,float nMidExam,float nFinalExam):
		Course(nMidExam ,nFinalExam) ,
		Person(nName, nOld)
		{
			this->SID = nSID; 
			this->SGrade = nSGrade; 
		}
		Student() : Person(),Course(){SID = "null", SGrade = 1;}
		friend ostream& operator<< (ostream& out,Student d) 
		{
			out << d.Name << "\t" << d.Old << "\t" << d.SID << "\t" << d.SGrade << "\t" << d.MidExam << "\t" << d.FinalExam <<"\t" << d.Average;
			return out;
		}  
};

int main()
{ 
	Student DataArray[100] ;
	
	int Count;
	fstream Fin("record.txt",ios::in);
	if (!Fin) exit(0);
	cout << "當前學生資料：" << endl;
	for(Count = 0;
		(Fin >> DataArray[Count].Name 
		     >> DataArray[Count].Old 
	         >> DataArray[Count].SID 
	         >> DataArray[Count].SGrade 
	         >> DataArray[Count].MidExam 
	         >> DataArray[Count].FinalExam) && (Count < 100);
		DataArray[Count].GetAvg(),cout << DataArray[Count] << endl, Count++);
	Fin.close();
	
	cout << "經排序後結果：" << endl;
	for(int i(0); i < Count; i++)
	{
		for(int j(i+1); j < Count; j++)
		{
			if (DataArray[j].Average > DataArray[i].Average)
			{
				Student Temp = DataArray[i];
				DataArray[i] = DataArray[j];
				DataArray[j] = Temp;
			}
		}
	}
	
	for(int i(0); i < Count; cout << DataArray[i] << endl, i++); 
	
	return 0; 
}


