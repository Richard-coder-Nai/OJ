/*************************************************************************
	> File Name: 00_io.cpp
	> Author: Yang Zhang 
	> Mail: zyziszy@foxmail.com 
	> Created Time: Sat 11 Jan 2020 07:52:04 AM CST
 ************************************************************************/

#include<iostream>
#include<iomanip>
using namespace std;


int main(void){
	float x=10.0/3;
	cout<<setiosflags(ios::fixed)<<setprecision(2)<<x<<endl;
}
