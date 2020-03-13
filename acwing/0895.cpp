#include<iostream>

using namespace std;

int nums[1005];
int f[1005];

int main(void){
	int n;
	cin>>n;

	for(int i=1; i<=n; i++){
		cin>>nums[i];
	}

	int mx = -1e9-1;
	for(int i=1; i<=n; i++){
		f[i] = 1;
		for(int j=1; j<i; j++){
			if(nums[i]>nums[j]){
				f[i] = max(f[i], f[j]+1);
			}
		}
		if(f[i]>mx) mx = f[i];
	}
	cout<<mx<<endl;
}
