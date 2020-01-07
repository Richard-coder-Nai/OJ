/*************************************************************************
	> File Name: 08_string.cpp
	> Author: Yang Zhang 
	> Mail: zyziszy@foxmail.com 
	> Created Time: Thu 02 Jan 2020 08:38:20 PM CST
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;


int main(void){
	string str = "this is a test";
	cout<<str.size()<<endl; //size = length
	cout<<str.find("this")<<endl; //find first match index
	cout<<str.find("test")<<endl; 
	// to uppper
	for (string:: iterator it=str.begin(); it!=str.end(); it++)
		*it = toupper(*it);
	cout << str << endl;

	// to lower
	for (string:: iterator it=str.begin(); it!=str.end(); it++)
		*it = tolower(*it);
	cout << str << endl;


}
