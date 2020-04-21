#include<iostream>

using namespace std;

int nums[100010];
int tmp[100010];

void merge_sort(int l, int r) {
	if(l>=r) return;
	int mid = l+r>>1;
	merge_sort(l, mid);
	merge_sort(mid+1, r);

	int i = l, j = mid+1;
	int k = 0;

	while(i<=mid && j<=r) {
		if(nums[i]<=nums[j]) tmp[k++] = nums[i++];
		else tmp[k++] = nums[j++];
	}

	while(i<=mid) tmp[k++] = nums[i++];
	while(j<=r) tmp[k++] = nums[j++];

	for(i=l, k=0; i<=r; i++, k++) {
		nums[i] = tmp[k];
	}
}


int main(void) {
	int n;
	cin>>n;
	for(int i=0; i<n; i++) cin>>nums[i];

	merge_sort(0, n-1);
	for(int i=0; i<n; i++) {
		cout<<nums[i]<<" ";
	}
	cout<<endl;
}
