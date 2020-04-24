/*************************************************************************
	> File Name: 04_iter.cpp
	> Author: Yang Zhang 
	> Mail: zyziszy@foxmail.com 
	> Created Time: Tue 31 Dec 2019 09:23:25 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main(void){
	//init
	vector<int> num_v = {10, 0, 1, 8, 4};
	for(auto item: num_v)
		cout<<item<<" ";
	cout<<endl;

	//sort
	sort(num_v.begin(), num_v.end());
	for(auto item: num_v)
		cout<<item<<" ";
	cout<<endl;

	//test
	for(vector<int>::iterator it=num_v.begin(); it!=num_v.end(); *it++)
		(*it)++;
	for(auto item: num_v)
		cout<<item<<" ";
	cout<<endl;

	for(vector<int>::iterator it=num_v.begin(); it!=num_v.end(); *it++)
		cout<<*it<<" ";
	cout<<endl;
}
