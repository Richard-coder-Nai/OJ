/*************************************************************************
  > File Name: 02_vector.cpp
  > Author: Yang Zhang
  > Mail: zyziszy@foxmail.com
  > Created Time: Tue 31 Dec 2019 06:35:19 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main(void){
	vector<int> num(10);
	cout<<"num size: "<<num.size()<<endl;
	cout<<"num capactiy: "<<num.capacity()<<endl;

	for(int i=0; i<num.size(); i++){
		num[i] = i+1;
	}

	cout<<"num: ";
	for(auto item : num){
		cout<<item<<" ";
	}
	cout<<endl;

	cout<<"nums: {1, 10, 0, 1, 8, 4}"<<endl;
	vector<int> nums = {1, 10, 0, 1, 8, 4};
	//sort
	sort(nums.begin(), nums.end());

	//ordered insert
	//upper_bound is not equal
	nums.insert(upper_bound(nums.begin(),nums.end(),1),1);
	for(auto it: nums) cout<<it<<" ";
		cout<<endl;

	//unique and erase
	auto it = unique(nums.begin(), nums.end());
	nums.erase(it, nums.end());
	for(auto it: nums) cout<<it<<" ";
	cout<<endl;
}
