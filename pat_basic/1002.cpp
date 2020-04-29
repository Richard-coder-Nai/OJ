/*************************************************************************
	> File Name: 1002.cpp
	> Author: Yang Zhang 
	> Mail: zyziszy@foxmail.com 
	> Created Time: Wed 01 Jan 2020 08:17:37 PM CST
 ************************************************************************/

#include<iostream>
#include<string>
#include<stack>
using namespace std;


int main(void){
	string str;
	cin>>str;

	int count = 0;
	for(int i=0; i<str.length(); i++){
		count += int(str[i] - '0');
	}

	stack<int> stk;
	while(count){
		stk.push(count%10);
		count = int(count/10);
	}
	
	while(!stk.empty()){
		int n = stk.top();
		switch(n){
			case 0:
				cout<<"ling";
				break;
			case 1:
				cout<<"yi";
				break;
			case 2:
				cout<<"er";
				break;
			case 3:
				cout<<"san";
				break;
			case 4:
				cout<<"si";
				break;
			case 5:
				cout<<"wu";
				break;
			case 6:
				cout<<"liu";
				break;
			case 7:
				cout<<"qi";
				break;
			case 8:
				cout<<"ba";
				break;
			case 9:
				cout<<"jiu";
				break;
			default:
				break;
		}

		stk.pop();
		if(!stk.empty()){
			cout<<" ";
		}
	}
	cout<<endl;
}
