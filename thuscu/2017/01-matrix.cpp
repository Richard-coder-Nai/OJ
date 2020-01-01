/*************************************************************************
	> File Name: 01-matrix.cpp
	> Author: Yang Zhang 
	> Mail: zyziszy@foxmail.com 
	> Created Time: Wed 01 Jan 2020 01:46:41 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


void print_fun(vector<vector<int>> matrix){
	int n = matrix.size();
	for(int i=0;i<n; i++){
		for(int j=0; j<n; j++){
			cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
	}
}


void trans(vector<vector<int>>& matrix){
	int n = matrix.size();
	int tmp = 0;
	for(int i=0;i<n; i++){
		for(int j=i; j<n; j++){
			tmp = matrix[i][j];
			matrix[i][j] = matrix[j][i];
			matrix[j][i] = tmp;
		}
	}
}

void row_shift(vector<vector<int>>& matrix, int k){
	int n = matrix.size();
	k = k%n;
	if(k){
		reverse(matrix.begin(), matrix.end());
		reverse(matrix.begin(), matrix.begin() + k - 1);
		reverse(matrix.begin() + k, matrix.end());
	}
}

void colum_shift(vector<vector<int>>& matrix, int k){
	int n = matrix.size();
	k = k%n;
	if(k){
		trans(matrix);
		row_shift(matrix, k);
		trans(matrix);
	}
}


int main(void){
	int n;
	cin>>n;
	vector<vector<int>> matrix(n);

	//int test = 0;
	for(int i=0;i<n; i++){
		for(int j=0; j<n; j++){
			int tmp;
			//test++;
			cin>>tmp;
			matrix[i].push_back(tmp);
			//test
			//matrix[i].push_back(test);
		}
	}
	//test
	//print_fun(matrix);
	//cout<<endl;
	//trans(matrix);
	//colum_shift(matrix, 2);
	//print_fun(matrix);
		
	cin>>n;
	for(int i=0;i<n; i++){
		int cs,k;
		cin>>cs;
		if(cs!=1) cin>>k;
		
		if(cs==1) trans(matrix);
		else if(cs == 2) row_shift(matrix, k);
		else colum_shift(matrix, k);
	}	
	print_fun(matrix);
}
