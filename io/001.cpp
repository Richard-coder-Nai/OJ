/*************************************************************************
	> File Name: 001.cpp
	> Author: Yang Zhang 
	> Mail: zyziszy@foxmail.com 
	> Created Time: Fri Mar 13 08:41:31 2020
 ************************************************************************/

#include<iostream>
using namespace std;


int a, b;
int main(void){
	int n;
	while(cin>>n){
		for(int i=0; i<n; i++){
			cin>>a>>b;
			cout<<a+b<<endl;
		}
	}
}
