/*************************************************************************
	> File Name: 1007_1.cpp
	> Author: Yang Zhang 
	> Mail: zyziszy@foxmail.com 
	> Created Time: Thu 02 Jan 2020 08:48:03 PM CST
 ************************************************************************/

#include<iostream>
#include<bitset>
#include<vector>
using namespace std;


bitset<100001> table;

int main(void){
	int n;
	cin>>n;
	if(n<=3){
		cout<<0<<endl;
		return 0;
	}

	table.set();
	//cout<<table<<endl;
	table[0] = 0;
	table[1] = 0;

	for(int i=2; i*i<100001; i++){
		if(table[i]){
			for(int j=i; i*j<100001; j++){
				table[i*j] = 0;
			}
		}
	}

	vector<int> primes;
	for(int i=2; i<=n; i++){
		if(table[i]){
			primes.push_back(i);
		}
	}

	int counter=0;
	for(int i=0; primes[i]<=n; i++){
		if(primes[i+1]<=n){
			if(primes[i+1]-primes[i]==2){
				counter++;
			}
		}
	}
	cout<<counter<<endl;	
}
