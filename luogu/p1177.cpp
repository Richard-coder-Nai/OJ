#include<iostream>

using namespace std;


int n, nums[100005];

void quick_sort(int l, int r){
	if(l>=r) return;
	int i = l-1;
	int j = r+1;
	int x = nums[l+r>>1];
	while(i<j){
		do{i++;} while(nums[i]<x);
		do{j--;} while(x<nums[j]);
		if(i<j) swap(nums[i], nums[j]);
	}
	quick_sort(l, j);
	quick_sort(j+1, r);
}

int main(void){
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d", &nums[i]);
	}
	quick_sort(0, n-1);
	for(int i=0; i<n; i++) cout<<nums[i]<<" ";
	cout<<endl;

}
