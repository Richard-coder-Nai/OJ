#include<iostream>

using namespace std;

int nums[105];

int n, k;
int main(void){
	cin>>k;
	while(k--){
		cin>>n;
		for(int i=0; i<n; i++) cin>>nums[i];
		if(n%2){
			cout<<nums[n/2]<<endl;
		}else{
			cout<<double((nums[n/2]+nums[n/2-1])/2.0)<<endl;
		}
	}
}
