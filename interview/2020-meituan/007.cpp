#include<iostream>
#include<vector>

using namespace std;

int n;
int main(void){
	while(cin>>n){
		vector<int> nums(2*n, 0);
		for(int i=0; i<2*n; i+=2){
			cin>>nums[i];
		}
		for(int i=1; i<2*n; i+=2){
			cin>>nums[i];
		}
		for(auto it:nums) cout<<it<<endl;
	}
}
