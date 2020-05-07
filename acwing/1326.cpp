#include <iostream>

using namespace std;

int n, k;
int nums[505];

int main(void) {
	cin>>n>>k;

	for(int i=0; i<n; i++) {
		cin>>nums[i];
	}

	sort(nums, nums+n);

	int res = 0;
	for(int i=0; i<n; i++) {
	}
	
	cout<<res<<endl;
}
