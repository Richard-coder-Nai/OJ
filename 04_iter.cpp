/*************************************************************************
	> File Name: 04_iter.cpp
	> Author: Yang Zhang 
	> Mail: zyziszy@foxmail.com 
	> Created Time: Tue 31 Dec 2019 09:23:25 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;


int main(void){
	vector<int> vec(100);
	for(int i=0; i<100; i++){
		vec[i]=i+1;
	}
	for(auto item: vec)
		cout<<item<<endl;
}
