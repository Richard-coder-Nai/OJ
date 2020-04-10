#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

const int N = 1e5+5;
int nums[N];

int main(void) {
	int n;
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>nums[i];
	}

	sort(nums, nums+n);

	int res = 0;
	int mid = nums[n/2];

	for(int i=0; i<n; i++){
		res += abs(nums[i]-mid);
	}
	cout<<res<<endl;
}
