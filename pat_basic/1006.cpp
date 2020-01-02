/*************************************************************************
	> File Name: 1006.cpp
	> Author: Yang Zhang 
	> Mail: zyziszy@foxmail.com 
	> Created Time: Thu 02 Jan 2020 11:13:58 AM CST
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;

int char2int(char c){
	return int(int(c) - int('0'));
}

int main(void){
	string num;
	cin>>num;


	int length = num.length();

	for(int i=0; i<length; i++){
		int pos = length-i;
		int n = char2int(num[i]);

		if(pos==3){
			for(int i=0; i<n; i++){
				cout<<"B";
			}
		}
		else if(pos==2){
			for(int i=0; i<n; i++){
				cout<<"S";
			}
		}
		else if(pos==1){
			for(int i=0; i<n; i++){
				cout<<i+1;
			}
		}
	}

	cout<<endl;
	return 0;	
}
