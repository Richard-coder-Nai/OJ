#include<iostream>

using namespace std;

int main(void){
	int n;
	cin>>n;

	int nums1[100005];
	int nums2[100005];

	int f[100005][100005];

	/*
	for(int i=1; i<=n; i++){
		cin>>nums1[i];
	}
	for(int i=1; i<=n; i++){
		cin>>nums2[i];
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if(nums1[i]==nums2[j]){
				f[i][j] = max(f[i][j], f[i-1][j-1]+1);
			}else{
				f[i][j] = max(f[i-1][j], f[i][j-1]);
			}
		}
	}
	cout<<f[n][n]<<endl;
	*/
}
