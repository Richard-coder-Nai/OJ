#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n;

int main(void){
	int n;
	cin>>n;
	vector<int> nums(n, 0);
	for(int i=0; i<n; i++){
		cin>>nums[i];
	}
	if(n==1){
		cout<<0<<endl;
		return 0;
	}
	sort(nums.begin(), nums.end());

	int couter = 0;
	while(nums.size()>1){
		int n = nums.size();
		int tmp = nums[0] + nums[1];
		couter += tmp;
		nums.erase(nums.begin());
		nums.erase(nums.begin());
		nums.insert(upper_bound(nums.begin(), nums.end(), tmp), tmp);
	}
	cout<<couter<<endl;

}
