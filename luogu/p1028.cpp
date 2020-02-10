#include<iostream>

using namespace std;

int dp[1005];

int main(void){
	dp[1] = 1;
	int n;
	cin>>n;
	for(int i=2; i<=n; i++){
		int tmp = i/2;
		dp[i] = 1;
		for(int j=1; j<=tmp; j++){
			dp[i] += dp[j];
		}
	}
	cout<<dp[n];
}

