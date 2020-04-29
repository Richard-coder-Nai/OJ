/*************************************************************************
	> File Name: 1005.cpp
	> Author: Yang Zhang 
	> Mail: zyziszy@foxmail.com 
	> Created Time: Tue 31 Dec 2019 08:39:40 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;


void caculator(int A, int B, int n){
	vector<int> table(49);
	table[0] = 1;
	table[1] = 1;
	for(int i=2; i<=49; i++)
		table[i] = ((A*table[i-1]) + (B*table[i-2]))%7;
	cout<<table[(n-1)%49]<<endl;
}

int main(void){
	int A,B,n;
	while(cin>>A>>B>>n){
		if(A==0 && B==0 && n==0) break;
		else caculator(A, B, n);
	}
	return 0;
}


