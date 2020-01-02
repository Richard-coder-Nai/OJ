/*************************************************************************
	> File Name: 1008.cpp
	> Author: Yang Zhang 
	> Mail: zyziszy@foxmail.com 
	> Created Time: Thu 02 Jan 2020 11:39:49 AM CST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main(void){
	int n,k;
	cin>>n>>k;
	k=k%n;
	
	vector<int> nums(n);
	for(int i=0; i<n; i++){
		cin>>nums[i];
		//nums[i] = i+1;
	}
	
	if(k){
		reverse(nums.begin(), nums.end());
		reverse(nums.begin(), nums.begin()+k);
		reverse(nums.begin()+k, nums.end());
	}

	for(int i=0; i<n-1; i++){
		cout<<nums[i]<<" ";
	}
	cout<<nums[n-1];
	cout<<endl;
}
