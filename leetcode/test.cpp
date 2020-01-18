#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
	vector<int> range(2,-1);
	if(nums.size()==0) return range;
	if(nums.size()==1){
		if(nums[0]==target){
			range[0]=0;
			range[1]=0;
			return range;
		}else{
			return range;
		}
	}
	auto lp=lower_bound(nums.begin(), nums.end(), target);
	auto up=upper_bound(nums.begin(), nums.end(), target);
	cout<<"*lp: "<<*lp<<endl;
	cout<<"*up: "<<*up<<endl;

	if((*lp)!=target) return range;
	else{
		range[0]=distance(nums.begin(), lp);
		range[1]=distance(nums.begin(), up)-1;
		return range;
	}
}

int main(void){
	vector<int> nums={2,2};
	vector<int> table=searchRange(nums, 3);
	for(auto v:table){
		cout<<v<<" "<<endl;
	}
}
