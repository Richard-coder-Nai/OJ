/*************************************************************************
	> File Name: 1002.cpp
	> Author: Yang Zhang 
	> Mail: zyziszy@foxmail.com 
	> Created Time: Tue 31 Dec 2019 02:24:33 PM CST
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;


int char_caculator(char c1, char c2){
	int n1 = c1 - '0';
	int n2 = c2 - '0';
	return n1 + n2;
}

char int2char(int n){
	return char(n + int('0'));
}


void sum_fun(int n, string str1, string str2){
	
	string big_str, small_str;

	if(str1.length() > str2.length()){
		big_str = str1;
		small_str = str2;
	}else{
		big_str = str2;
		small_str = str1;
	}


	string zero_string = "";
	for(int i=0; i<(big_str.length()-small_str.length()); i++){
		zero_string += "0";
	}
	small_str = zero_string + small_str;


	int temp;
	bool carry = false;

	for(int i=big_str.length()-1; i >= 0 ; i--){
		temp = char_caculator(big_str[i], small_str[i]);
		if(carry) temp++;
	
		if(temp>=10){
			carry = true;
			big_str[i] = int2char(temp%10);
		}else{
			carry = false;
			big_str[i] = int2char(temp);
		}
	}

	//output
	cout<<"Case "<<n<<":"<<endl;
	cout<<str1<<" + "<<str2<<" = ";
	if(carry) cout<<1;
	cout<<big_str<<endl;
	
}

int main(void){
	int n;	
	cin>>n;

	string str1,str2;
	for(int i=0; i<n; i++){
		cin>>str1>>str2;	
		sum_fun(i+1, str1, str2);

		//avoid presentation Error
		if(i < n-1)
			cout<<endl;
	}
}
