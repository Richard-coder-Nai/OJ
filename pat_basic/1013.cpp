/*************************************************************************
	> File Name: 1013.cpp
	> Author: Yang Zhang 
	> Mail: zyziszy@foxmail.com 
	> Created Time: Wed 01 Jan 2020 09:28:36 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

bool isPrime(int n){
	bool prime = true;
	for(int i=2; i*i<=n; i++){
		if(n%i==0){
			prime = false;
			break;
		}
	}
	return prime;
}

int main(void){
	int m,n;
	cin>>m>>n;

	vector<int> prime_table;
	prime_table.push_back(2);
	
	int num = 3;
	for(int i=1; i<n; i++){
		while(!isPrime(num)){
			num++;
		}
		prime_table.push_back(num);
		num++;
	}
	
//	for(auto item:prime_table)
//		cout<<item<<" ";
//	cout<<endl;
//	cout<<endl;

	int count = 1;
	for(int i=m-1; i<n-1; i++){
		cout<<prime_table[i];
		if(count%10) cout<<" ";
		else cout<<endl;
		count++;
	}
	cout<<prime_table[n-1]<<endl;
}
