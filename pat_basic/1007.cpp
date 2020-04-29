/*************************************************************************
	> File Name: 1007.cpp
	> Author: Yang Zhang 
	> Mail: zyziszy@foxmail.com 
	> Created Time: Thu 02 Jan 2020 10:44:17 AM CST
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;



int main(void){
	long n;
	cin>>n;

	if(n<=2){
		cout<<0<<endl;
		return 0;
	}

	//build prime table
	vector<int> nums;
	nums.assign(n+1,1);
	nums[0] = 0;
	nums[1] = 0;
	for(int i=2; i*i<=n; i++){
		if(nums[i]){
			for(int j=i; j*i<n; j++){
				nums[j*i] = 0;
			}
		}
	}

	//prime
	vector<int> prime_table;
	for(int i=2; i<=n; i++){
		if(nums[i])
			prime_table.push_back(i);
	}

	
	int counter = 0;
	int i=0;
	while(prime_table[i]<=n){
		if(prime_table[i+1]<=n){
			if(prime_table[i+1]-prime_table[i] == 2){
				counter++;
			}
		}
		i++;
	}
	cout<<counter<<endl;
	return 0;

}
