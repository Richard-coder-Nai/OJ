/*************************************************************************
	> File Name: 1002_1.cpp
	> Author: Yang Zhang 
	> Mail: zyziszy@foxmail.com 
	> Created Time: Tue 31 Dec 2019 03:44:48 PM CST
 ************************************************************************/

#include<iostream>
#include<algorthm>
#include<string>
using namespace std;


int char2int(char c){
	return int(c - int('0'));
}

int char_caculator(char c1, char c2){
	return int(c1) + int(c2) - int('0')*2;
}

void Sum_fun(string str1, string str2){
	string big_str, small_str;
	if(str1.length() > str2.length()){
		big_str = str1;
		small_str = str2;
	}else{
		big_str = str2;
		small_str = str1;
	}
	reverse(big_str.begin(),big_str.end());
	reverse(small_str.begin(),small_str.end());

	bool carry = false;
	for(int i=0; i<big_str.length(); i++){
		
	}
}
	

int main(void){
	int n;
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>str1>>str2;
	}
	
}


