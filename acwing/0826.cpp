#include<iostream>
#include<algorithm>

using namespace std;

int n;
int nums[1005];
int f[1005];


int main(void){
	cin>>n;
	for(int i=1; i<=n; i++){
		cin>>nums[i];
	}

	for(int i=1; i<=n; i++){
		f[i] = nums[i];
		int add = 0;
		for(int j=0; j<i; j++){
			if(nums[i]>nums[j]){
				add = max(add, f[j]);
			}
		}
		f[i] += add;
	}
	cout<<*max_element(f, f+n+1)<<endl;
}
