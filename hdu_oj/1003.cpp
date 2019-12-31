/*************************************************************************
	> File Name: 1003.cpp
	> Author: Yang Zhang 
	> Mail: zyziszy@foxmail.com 
	> Created Time: Tue 31 Dec 2019 06:19:59 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;


void solve(int size, vector<int> num){
	vector<int> sum(size);
	vector<int> start(size);

	sum[0] = num[0];
	start[0] = 0;

	for(int i=1; i<size; i++){
		int temp = num[i] + sum[i-1];
		if(temp>=num[i]){
			sum[i] = temp;
			start[i] = start[i-1];
		}else{
			sum[i] = num[i];
			start[i] = i;
		}
	}
	
	//test
	//cout<<"num: ";
	//for(auto item : num){
	//	cout<<item<<" ";
	//}
	//cout<<endl;
	//cout<<"sum: ";
	//for(auto item : sum){
	//	cout<<item<<" ";
	//}
	//cout<<endl;

	int max_index = 0;
	for(int i=1; i<size; i++){
		if(sum[max_index] < sum[i])
			max_index = i;
	}
	cout<<sum[max_index]<<" "<<start[max_index]+1<<" "<<max_index+1<<endl;
}

int main(void){
	int n;
	cin>>n;

	for(int i=0; i<n; i++){
		int size;
		cin>>size;
		
		vector<int> num(size);
		for(int j=0; j<size; j++){
			cin>>num[j];
		}
		
		cout<<"Case "<<i+1<<":"<<endl;
		solve(size, num);

		if(i<n-1)
			cout<<endl;
	}
}
