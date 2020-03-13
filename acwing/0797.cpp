#include<iostream>

using namespace std;

int nums[100005];
int d[100005];
int n, m;
int main(void){
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		cin>>nums[i];
		d[i] = nums[i]-nums[i-1];
	}

	while(m--){
		int l, r, c;
		cin>>l>>r>>c;

		d[l] += c;
		d[r+1] -=c;
	}

	for(int i=1; i<=n; i++){
		d[i] = d[i]+d[i-1];
		cout<<d[i]<<" ";
	}
	cout<<endl;
}
