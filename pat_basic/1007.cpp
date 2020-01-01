/*************************************************************************
	> File Name: 1007.cpp
	> Author: Yang Zhang 
	> Mail: zyziszy@foxmail.com 
	> Created Time: Wed 01 Jan 2020 08:55:11 PM CST
 ************************************************************************/

#include<iostream>
#include<string>

using namespace std;



int main(void){
	string str;
	int n;
	cin>>str>>n;

	string q;
	int r = 0;
	for(int i=0; i<int(str.length()); i++){
		int tmp = int(str[i]-int('0'));
		tmp = tmp +10*r;
		r = tmp%n;
		tmp = tmp/n;

		if(i==0){
			if(tmp)	
				q.push_back(char(int('0')+tmp));
		}else{
			q.push_back(char(int('0')+tmp));
		}
	}
	cout<<q<<" "<<r<<endl;
}
