/*************************************************************************
	> File Name: 03_map.cpp
	> Author: Yang Zhang 
	> Mail: zyziszy@foxmail.com 
	> Created Time: Tue 31 Dec 2019 07:52:47 PM CST
 ************************************************************************/

#include<iostream>
#include<map>
#include<string>
using namespace std;


int main(void){
	map<string, int> my_map;
	my_map["alex"] = 1;
	my_map["zhang"] = 1;
	cout<<my_map["alex"]<<endl;
	cout<<my_map["zhang"]<<endl;

	for(auto item:my_map){
		cout<<item.first<<" "<<item.second<<endl;
	}

	if(my_map.count("test")==0)
		cout<<"test does not exisit"<<endl;

	if(my_map.count("zhang"))
		cout<<"zhang exisits"<<endl;
}
