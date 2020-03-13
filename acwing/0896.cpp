#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int N = 1e5+5;
int nums[N];

int main(void){
	int n;
	cin>>n;
	for(int i = 0; i<n; i++){
		cin>>nums[i];
	}
	vector<int> table; 
	table.push_back(nums[0]);
	for(int i=1; i<n; i++){
		if(nums[i]>table.back()){
			table.push_back(nums[i]);
		}
		if(nums[i]<table.back()){
			*lower_bound(table.begin(), table.end(), nums[i]) = nums[i];
		}
	}
	cout<<table.size()<<endl;
}
