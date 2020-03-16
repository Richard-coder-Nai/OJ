#include<iostream>

using namespace std;


int n, q, nums[10005];;

int up(int x){
	int l = 0, r = n-1;
	while(l<r){
		int mid = l+r>>1;
		if(nums[mid]>=x) r = mid;
		else l = mid+1;
	}
	if(nums[l]!=x) return -1;
	else return l;
}

int down(int x){
	int l = 0, r = n-1;
	while(l<r){
		int mid = l+r>>1;
		if(nums[mid]<=x) l = mid;
		else r = mid-1;
	}
	if(nums[l]!=x) return -1;
	else return l;
}

int main(void){
	cin>>n>>q;
	for(int i=0; i<n; i++){
		scanf("%d", &nums[i]);
	}
	for(int i=0; i<q; i++){
		int x;
		scanf("%d", &x);
		cout<<down(x)<<" "<<up(x)<<endl;
	}
}
