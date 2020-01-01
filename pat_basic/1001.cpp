/*************************************************************************
	> File Name: 1001.cpp
	> Author: Yang Zhang 
	> Mail: zyziszy@foxmail.com 
	> Created Time: Wed 01 Jan 2020 12:53:29 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;


int main(void){
	//input
	int a;
	cin>>a;

	int count = 0;
	while(a!=1){
		if( a%2 ) a = 3 * a + 1;
		a = a / 2;
		count++;
	}
	cout<<count<<endl;
}
