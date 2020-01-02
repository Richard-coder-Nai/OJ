/*************************************************************************
	> File Name: 1009.cpp
	> Author: Yang Zhang 
	> Mail: zyziszy@foxmail.com 
	> Created Time: Thu 02 Jan 2020 03:42:08 PM CST
 ************************************************************************/

#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main(void){
	string tmp;
	stack<string> stk;

	string str;
	getline(cin, str);

	for(int i=0; i<int(str.length()); i++){
		if(str[i]==' '){
			stk.push(tmp);
			tmp.clear();
			tmp = "";
		}
		else{
			tmp.push_back(str[i]);
		}

		if(i==int(str.length()-1)){
			stk.push(tmp);
		}
	}
	
	while(!stk.empty()){
		cout<<stk.top();
		stk.pop();
		if(!stk.empty())
				cout<<" ";
	}
	cout<<endl;
}

