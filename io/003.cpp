/*************************************************************************
	> File Name: 003.cpp
	> Author: Yang Zhang 
	> Mail: zyziszy@foxmail.com 
	> Created Time: Fri Mar 13 08:45:03 2020
 ************************************************************************/

#include<iostream>
using namespace std;


int a, b;

int main(void){
	while(cin>>a>>b){
		if(a==b && a==0) return 0;
		cout<<a+b<<endl;
	}
}
