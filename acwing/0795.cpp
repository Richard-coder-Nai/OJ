#include<iostream>

using namespace std;

const int N = 100005;

int n, k;
int nums[N];
int sum[N];

int main(void){
	cin>>n>>k;

	for(int i=1; i<=n; i++){
		cin>>nums[i];
		sum[i] = sum[i-1]+nums[i];
	}

	for(int i=0; i<k; i++){
		int l, r;
		cin>>l>>r;
		cout<<sum[r]-sum[l-1]<<endl;
	}
}
