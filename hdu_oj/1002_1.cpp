/*************************************************************************
	> File Name: 1002_1.cpp
	> Author: Yang Zhang 
	> Mail: zyziszy@foxmail.com 
	> Created Time: Tue 31 Dec 2019 03:44:48 PM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<string>
using namespace std;


char int2char(int n){
	return char(n + int('0'));
}

int char_adder(char c1, char c2){
	int n1 = int(c1) - int('0');
	int n2 = int(c2) - int('0');
	return n1 + n2;
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
	int temp = 0;
	for(int i=0; i<big_str.length(); i++){
		if(i<small_str.length()){
			temp = char_adder(big_str[i], small_str[i]);
		}else{
			temp = char_adder(big_str[i], '0');
		}
		if(carry) temp++;

		if(temp>=10){
			carry = true;
			big_str[i] = int2char(temp%10);
		}else{
			carry = false;
			big_str[i] = int2char(temp);
		}
	}
	if(carry)
		cout<<1;
	reverse(big_str.begin(),big_str.end());
	cout<<big_str<<endl;

}
	

int main(void){
	int n;
	cin>>n;
	for(int i=0; i<n; i++){
		string str1, str2;
		cin>>str1>>str2;
		Sum_fun(str1, str2);
	}
	
}

