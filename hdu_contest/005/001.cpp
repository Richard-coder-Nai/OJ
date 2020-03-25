#include<iostream>
#include<cstdio>

using namespace std;

int t, n;
int nums[10005];

int main(void){
	cin>>t;
	while(t--){
		scanf("%d", &n);
		float res = 0;
		for(int i=0; i<n; i++){
			scanf("%d", &nums[i]);
		}
		for(int i=0; i<n; i++){
			int k = (i+1)%n;
			if(nums[i]==nums[k]){
				res += float(1.0/nums[i]);
			}
			if(nums[i]>nums[k]){
				res += float(1.0/nums[i]);
			}
			if(nums[i]<nums[k]){
				res += float(1.0/nums[k]);
			}
		}
		printf("%.2f\n", res);
	}
}
