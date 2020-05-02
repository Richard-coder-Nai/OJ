#include <iostream>

using namespace std;

const int N = 1e3+4;
int n;
int nums[N];
int f[N];

int main(void) {
	cin>>n;
	for(int i=0; i<n; i++) 
		cin>>nums[i];

	f[0] = 1;
	int res = 1;
	for(int i=1; i<n; i++) {
		f[i] = 1;
		for(int j=0; j<i; j++) {
			if(nums[i]>nums[j]) {
				f[i] = max(f[j]+1, f[i]);
			}
		}
		res = max(res, f[i]);
	}
	cout<<res<<endl;
}
