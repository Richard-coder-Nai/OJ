/*************************************************************************
	> File Name: 1016.cpp
	> Author: Yang Zhang 
	> Mail: zyziszy@foxmail.com 
	> Created Time: Sat 11 Jan 2020 08:00:54 AM CST
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;


int main(void){
	string A, B;
	string a,b;
	cin>>A>>a>>B>>b;

	string PA,PB;
	for(auto it:A){
		if(it==a[0])
			PA=PA+a;
	}
	for(auto it:B){
		if(it==b[0])
			PB=PB+b;
	}

	int PA_int, PB_int;
	PA_int=atoi(PA.c_str());
	PB_int=atoi(PB.c_str());

	cout<<PA_int+PB_int<<endl;
}
