#include<iostream>
#include<vector>
#include<cstdio>

using namespace std;

const int N = 1e8+5;

int n, q, k;
int prime[5000010];

int main(void){
	scanf("%d %d", &n, &q);
	vector<bool> nums(n+1, true);
	nums[0] = false;
	nums[1] = false;
	
	int idx = 1;
	for(int i=2; i<=n; i++){
		if(nums[i]){
			prime[idx] = i;
			idx++;
			for(int j=2; j<=n/i; j++){
				nums[i*j] = false;
			}
		}
	}
	for(int i=0; i<q; i++){
		scanf("%d", &k);
		cout<<prime[k]<<endl;
	}
}
