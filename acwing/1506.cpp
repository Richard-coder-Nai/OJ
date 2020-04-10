#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int N = 2e5+4;
int nums1[N];
int nums2[N];
int n1, n2;

int main(void){
	cin>>n1;
	for(int i=0; i<n1; i++){
		scanf("%d", &nums1[i]);
	}
	cin>>n2;
	for(int i=0; i<n2; i++){
		scanf("%d", &nums2[i]);
	}

	int n = (n1+n2)/2+(n1+n2)%2;
	int i = 0;
	int j = 0;
	int cnt = 0;
	int mid = -1;
	while(cnt<n){
		if(nums1[i]<nums2[j]){
			mid = nums1[i];
			i++;
		}else{
			mid = nums2[j];
			j++;
		}
		//cout<<mid<<endl;
		cnt++;
	}
	cout<<mid<<endl;
}
