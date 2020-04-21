#include<iostream>

using namespace std;

int nums[100010];
int tmp[100010];

long long merge_sort(int l, int r){
	if(l>=r) return 0;

	int mid = l+r>>1;
	long long res = merge_sort(l, mid) + merge_sort(mid+1, r);

	int i = l, j = mid+1;
	int k = 0;
	while(i<=mid && j<=r) {
		if(nums[i]<=nums[j]){
			tmp[k++] = nums[i++];
		}else{
			tmp[k++] = nums[j++];
			res += mid-i+1;
		}
	}
	while(i<=mid) {
		tmp[k++] = nums[i++];
	}
	while(j<=r) {
		 tmp[k++] = nums[j++];
	}
	for(i = l, k=0; i<=r; i++, k++) {
		nums[i] = tmp[k];
	}
	return res;
}

int n;
int main(void) {
	cin>>n;
	for(int i=0; i<n; i++) {
		cin>>nums[i];
	}
	cout<<merge_sort(0, n-1)<<endl;
}
