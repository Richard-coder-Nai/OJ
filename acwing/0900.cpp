#include<iostream>

using namespace std;

const int mod = 1e9+7;

int f[1005];

int main(void){
	int n;
	cin>>n;
	f[0] = 0;
	f[1] = 1;
	for(int i=1;i<=n; i++){
		f[i] = 1;
		for(int j=1; j<i; j++){
			f[i] = (f[i] + f[j])%mod;
		}
	}
	cout<<f[n]<<endl;
}
