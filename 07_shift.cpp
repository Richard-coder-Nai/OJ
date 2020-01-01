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

//left shift
//reverse 3 times
int main(void){
	vector<int> n;
	for(int i =0; i<10; i++){
		n.push_back(i+1);
	}
	for(int i =0; i<10; i++){
		cout<<n[i]<<" ";
	}
	cout<<endl;

	reverse(n.begin(), n.end());

	for(int i =0; i<10; i++){
		cout<<n[i]<<" ";
	}
	cout<<endl;

	int k = 5;	

	reverse(n.begin(), n.end()-k);
	reverse(n.end()-k+1, n.end());
	for(int i =0; i<10; i++){
		cout<<n[i]<<" ";
	}

	cout<<endl;

}
