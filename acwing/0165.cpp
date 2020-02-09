#include<iostream>

using namespace std;

int c[20];
int dp[20][2000];

int main(void){
	long n, w;
	cin>>n>>w;
	for(long i=0; i<n; i++) cin>>c[i];

	for(long i=1; i<n; i++){ // i is cat idx
		for(long j=1; j<w; j++){ // j is cost
			dp[i][j] = dp[i-1][j];
			if(j>=c[i]){
				dp[i][j] = min(dp[i][j], dp[i-1][j-c[i]]+1);
			}
		}
	}
	cout<<dp[n][w];
}
