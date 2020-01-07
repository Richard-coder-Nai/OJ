/*************************************************************************
	> File Name: 1018.cpp
	> Author: Yang Zhang 
	> Mail: zyziszy@foxmail.com 
	> Created Time: Sun 05 Jan 2020 05:31:37 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

bool judgeA_win(char A, char B){
	if(A=='J'&&B=='C') return false;
	else if(A=='J'&&B=='B') return true;
	else if(A=='B'&&B=='C') return true;
	else if(A=='B'&&B=='J') return false;
	else if(A=='C'&&B=='B') return true;
	else if(A=='C'&&B=='J') return false;
	return true;
		
}

int main(void){
	int n;
	cin>>n;

	vector<int> count_A;
	vector<int> count_B;
	int count_P=0;
	count_A.assign(128, 0);
	count_B.assign(128, 0);

	for(int i=0; i<n; i++){
		char A, B;	
		cin>>A>>B;
		
		if(A==B){
			count_P++
		}else{
			if(judgeA_win(A, B)){
				count_A[int(A)]++;
			}else{
				count_B[int(B)]++;
			}
		}
	}

	int max_A_index=0;
	int A_win=0;
	for(int i=0; i<128; i++){
		item=
	}

	int max_B_index=0;
	for(int i=0; i<128; i++){

	

	
}
