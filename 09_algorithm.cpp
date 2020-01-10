/*************************************************************************
	> File Name: 09_algorithm.cpp
	> Author: Yang Zhang 
	> Mail: zyziszy@foxmail.com 
	> Created Time: Sat 11 Jan 2020 12:14:14 AM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;


int main(void){
	string str1="defgabc";
	string str2="hijklmn";
	cout<<"str1: "<<str1<<endl<<"str2: "<<str2<<endl;
	
	//swap
	swap(str1, str2);
	
	//max and min
	cout<<"max: "<<min(str1, str2)<<endl;
	cout<<"max: "<<max(str1, str2)<<endl;

	vector<int> a = {7,1,1,8,9,3,4,1,3,2};
	for(auto item:a) cout<<item<<" ";
	cout<<endl;

	//max and min element
	cout<<"max: "<<*max_element(a.begin(), a.end())<<endl;
	cout<<"min: "<<*min_element(a.begin(), a.end())<<endl;

	//sort
	sort(a.begin(), a.end());
	for(auto item:a) cout<<item<<" ";
	cout<<endl;

	//unique
	vector<int>::iterator it = unique(a.begin(), a.end());
	a.erase(it, a.end());
	for(auto item:a) cout<<item<<" ";
	cout<<endl;

	//cout<<*binary_search(a.begin(), a.end(), 4)<<endl;
	cout<<"lower bound of 4: "<<*lower_bound(a.begin(), a.end(), 4)<<endl;
	cout<<"upper bound of 4: "<<*upper_bound(a.begin(), a.end(), 4)<<endl;
}
