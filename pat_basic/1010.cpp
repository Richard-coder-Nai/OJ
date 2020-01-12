/*************************************************************************
	> File Name: 1010.cpp
	> Author: Yang Zhang 
	> Mail: zyziszy@foxmail.com 
	> Created Time: Sun 12 Jan 2020 10:59:32 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int main(void){
	int c,n;	
	bool flag=false; //judge if end or not

	while(cin>>c>>n){
		if(c*n){
			if(flag)
				cout<<" ";
			else
				flag=true;
		}else if(n==0){
			break;
		}
	}

	if(!flag)
		cout<<"0 0"<<endl;
}
