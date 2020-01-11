/*************************************************************************
	> File Name: 08_string.cpp
	> Author: Yang Zhang 
	> Mail: zyziszy@foxmail.com 
	> Created Time: Thu 02 Jan 2020 08:38:20 PM CST
 ************************************************************************/

#include<iostream>
#include<string>
#include<sstream>
using namespace std;


int main(void){
	string str = "this is a test";

	// size = length
	cout<<str.size()<<endl; 

	// find first match index
	cout<<str.find("this")<<endl; 

	// npos can not find
	if(str.find("z")==str.npos)
		cout<<"can not find z"<<endl;

	// to uppper
	for (string:: iterator it=str.begin(); it!=str.end(); it++)
		*it = toupper(*it);
	cout << str << endl;

	// to lower
	for (string:: iterator it=str.begin(); it!=str.end(); it++)
		*it = tolower(*it);
	cout << str << endl;

	// stirngstream split space
	stringstream stream;
	stream<<str;
	while(stream>>str)
		cout<<str<<endl;

	//convert the string to int
	int n;
	str="1234";
	n=atoi(str.c_str());
	cout<<"n: "<<n<<endl;
}
