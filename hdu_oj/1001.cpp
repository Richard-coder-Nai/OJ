/*************************************************************************
	> File Name: 1001.cpp
	> Author: Yang Zhang 
	> Mail: zyziszy@foxmail.com 
	> Created Time: Tue 31 Dec 2019 12:15:21 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;


int main(void){
	int n;
	long sum=0;
	while(cin>>n){
		for(int i=1; i<=n; i++)
			sum+=i;
		cout<<sum<<endl<<endl;
		sum = 0;
	}
}
