/*************************************************************************
	> File Name: 02_vector.cpp
	> Author: Yang Zhang 
	> Mail: zyziszy@foxmail.com 
	> Created Time: Tue 31 Dec 2019 06:35:19 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;


int main(void){
	vector<int> num(10);
	cout<<num.size()<<endl;

	for(int i=0; i<num.size(); i++){
		num[i] = i+1;
	}


	cout<<"num: ";
	for(auto item : num){
		cout<<item<<" ";
	}

	cout<<endl;
}
