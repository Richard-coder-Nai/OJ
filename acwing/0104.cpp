#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

vector<int> nums;

int main(void){
	int n;
	cin>>n;
	nums.assign(n, 0);
	for(int i=0; i<n; i++) cin>>nums[i];
	sort(nums.begin(), nums.end());

	int sum = 0;
	for(int i=0; i<n; i++){
		sum += abs(nums[i]-nums[n/2]);
	}
	cout<<sum<<endl;
}
