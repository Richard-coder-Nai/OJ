#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


vector<int> searchRange(vector<int>& nums, int target);

int main(void){
	vector<int> nums={1, 1, 1, 1};
	int target = 3;
	auto lb = lower_bound(nums.begin(), nums.end(), target);
	auto ub = upper_bound(nums.begin(), nums.end(), target);

	cout<<distance(nums.begin(), lb)<<endl;
	cout<<distance(nums.begin(), ub)<<endl;

	vector<int> range=searchRange(nums, 0);
	for(auto it:range){
		cout<<it<<" "<<endl;
	}
	cout<<endl;
}


vector<int> searchRange(vector<int>& nums, int target) {
	vector<int> scale={-1,-1};
	if(nums.size()==0) return scale;

	vector<int>::iterator p_l = lower_bound(nums.begin(), nums.end(), target);
	vector<int>::iterator p_u = upper_bound(nums.begin(), nums.end(), target);
	if((*p_l)==target){
		int l_index=distance(nums.begin(), p_l);
		int u_index=distance(nums.begin(), p_u)-1;
		scale[0]=l_index;
		scale[1]=u_index;
	}

	return scale;
}
