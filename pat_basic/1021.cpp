/*************************************************************************
	> File Name: 1021.cpp
	> Author: Yang Zhang 
	> Mail: zyziszy@foxmail.com 
	> Created Time: Sun 12 Jan 2020 08:59:16 AM CST
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;


int main(void){
	string num;
	cin>>num;
	int table[10]={0};
	for(auto it=num.begin(); it!=num.end(); it++){
		table[int(*it-'0')]+=1;
	}
	for(int i=0; i<10; i++){
		if(table[i]){
			cout<<i<<":"<<table[i]<<endl;
		}
	}
}
