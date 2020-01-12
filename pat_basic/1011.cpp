/*************************************************************************
	> File Name: 1011.cpp
	> Author: Yang Zhang 
	> Mail: zyziszy@foxmail.com 
	> Created Time: Sun 12 Jan 2020 08:51:17 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;


int main(void){
	int n;
	cin>>n;
	for(int i=1; i<=n; i++){
		long long a, b, c;
		cin>>a>>b>>c;

		if(a+b>c){
			cout<<"Case #"<<i<<": true"<<endl;
		}else{
			cout<<"Case #"<<i<<": false"<<endl;
		}
	}
}
