/*************************************************************************
	> File Name: 07_shift.cpp
	> Author: Yang Zhang 
	> Mail: zyziszy@foxmail.com 
	> Created Time: Wed 01 Jan 2020 02:20:44 PM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

void print_fun(vector<int> nums){
	for(auto item:nums)
		cout<<item<<" ";
	cout<<endl;
}

void left_shift(vector<int> nums, int k){
	reverse(nums.begin(), nums.end());
	reverse(nums.begin(), nums.end());
	reverse(nums.begin(), nums.end());
	print_fun(nums);
}

void right_shift(vector<int> nums, int k){
	reverse(nums.begin(), nums.end());
	reverse(nums.begin(), nums.end());
	reverse(nums.begin(), nums.end());
	print_fun(nums);
}


int main(void){
	//init vector
	vector<int> nums(10);
	for(int i=0; i<nums.size(); i++){
		nums[i] = i+1;
	}
	print_fun(nums);
	left_shift();
	right_shift();
}
