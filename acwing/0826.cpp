#include<iostream>
#include<vector>

using namespace std;

vector<int> nums;
char opt;

int main(void){
	int M;
	cin>>M;

	while(M--){
		cin>>opt;
		if(opt=='H'){
			int n;
			cin>>n;
			nums.insert(nums.begin(), n);
		}
		if(opt=='I'){
			int k, n;
			cin>>k>>n;
			nums.insert(nums.begin()+k-1, n);
		}
		if(opt=='D'){
			int n;
			cin>>n;
			if(n==0){
				nums.erase(nums.begin());
			}else{
				if(n<nums.size())
					nums.erase(nums.begin()+n+1, nums.end());
			}
		}
		for(auto it:nums){
			cout<<it<<" ";
		}
		cout<<endl;
	}
	for(auto it:nums){
		cout<<it<<" ";
	}
	cout<<endl;
}
