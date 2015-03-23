#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

string GetSource()
{
	string temp_str_source;
	ifstream fin("source.cpp");
	if (!fin) return "";
	for(string current_temp;getline(fin,current_temp);temp_str_source+=current_temp +"\n");
	fin.close();
	return (temp_str_source);
}
void SaveSourceToNew(string OutputContent)
{
	ofstream fout("new_source.cpp");
	if (!fout) return;
	fout << OutputContent;
    fout.close();
}

int main()
{
	string user_source = GetSource();
 	cout << "截取到程式碼:\n\n" << user_source;
 	int pos_for = user_source.find("for");
 	int pos_left_start = user_source.find("(",pos_for);
    int pos_right_end  = user_source.find(")",pos_for);
	int pos_blocksymbol_1 = user_source.find(";", pos_left_start);
    int pos_blocksymbol_2 = user_source.find(";", pos_blocksymbol_1 + 1);
    int pos_current_for_blockend = user_source.find("}",pos_right_end);
    
    string method_left_content = user_source.substr(pos_left_start + 1, pos_blocksymbol_1 - pos_left_start - 1);
    string method_mid_content = user_source.substr(pos_blocksymbol_1 + 1, pos_blocksymbol_2 - pos_blocksymbol_1 - 1);
	string method_right_content = user_source.substr(pos_blocksymbol_2 + 1, pos_right_end - pos_blocksymbol_2 - 1);
	method_right_content.append(";\n");
	method_left_content.append(";\n");

	user_source.insert(pos_current_for_blockend,method_right_content);
    user_source.replace(pos_left_start + 1, pos_right_end - pos_left_start - 1 ,method_mid_content);
    user_source.replace(pos_for , 3 , "while");
    user_source.insert(pos_for -1,method_left_content);
 	
 	cout << "變異後的程式碼:\n\n" << user_source;
	SaveSourceToNew(user_source);
    system("pause");
    return 0;
}
