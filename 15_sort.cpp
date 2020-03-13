/*************************************************************************
	> File Name: 15_sort.cpp
	> Author: Yang Zhang 
	> Mail: zyziszy@foxmail.com 
	> Created Time: Tue 11 Feb 2020 02:41:47 PM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;

struct node{
	int idx;
	int val;
	node(int index, int value):idx(index), val(value){}
};

bool cmp1(int a, int b){
	return a>b;
}

bool cmp2(node a, node b){
	return a.val>b.val;
}


int main(void){
	vector<int> nums = {2,3,1};

	for(auto it:nums) cout<<it<<" ";
	cout<<endl;

	sort(nums.begin(), nums.end());

	for(auto it:nums) cout<<it<<" ";
	cout<<endl;

	sort(nums.begin(), nums.end(), cmp1);
	for(auto it:nums) cout<<it<<" ";
		cout<<endl;

	node n1(1,2);
}
