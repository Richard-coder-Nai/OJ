#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n;
vector<int> nums;
int main(void){
	cin>>n;
	nums.resize(n);
	for(int i=0; i<n; i++) cin>>nums[i];
	sort(nums.begin(), nums.end());

	int res = 0;
	while(nums.size()>1){
		int tmp = nums[0]+nums[1];
		res += tmp;
		nums.erase(nums.begin());
		nums.erase(nums.begin());
		vector<int>::iterator pos = upper_bound(nums.begin(), nums.end(), tmp);
		nums.insert(pos, tmp);
	}
	cout<<res;
}
