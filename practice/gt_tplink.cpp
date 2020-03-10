#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> nums = {1, 2, 3, 4, 1, 2, 3, 6, 7};
vector<int> f;


int main(void){
	for(auto it:nums) cout<<it<<" ";
	cout<<endl;

	int n = nums.size();
	f.assign(n, 1);

	int mx = 1;
	int mx_idx = 0;

	for(int i=1; i<n; i++){
		for(int j=0;j<i; j++){
			if(nums[i]>nums[j]){
				f[i] = max(f[i], f[j]+1);
				if(f[i]>mx){
					mx = f[i];
					mx_idx = i;
				}
			}
		}
	}
	vector<int> res;
	while(mx!=0){
		res.push_back(nums[mx_idx]);
		mx--;
		while(mx_idx>=0){
			mx_idx--;
			if(f[mx_idx]==mx) break;
		}
	}
	reverse(res.begin(), res.end());
	for(auto it:res) cout<<it<<" ";
	cout<<endl;
}
