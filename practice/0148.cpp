#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int main(void){
	int n;
	cin>>n;
	vector<int> nums(n, 0);

	for(int i=0; i<n; i++){
		cin>>nums[i];
	}

	sort(nums.begin(), nums.end());

	int res = 0;
	while(nums.size()>1){
		int tmp = nums[0] + nums[1];
		res += tmp;
		auto pos = upper_bound(nums.begin(), nums.end(), tmp);
		nums.insert(pos, tmp);
		nums.erase(nums.begin());
		nums.erase(nums.begin());
	}
	cout<<res<<endl;
}
