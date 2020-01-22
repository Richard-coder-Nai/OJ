#include<iostream>
#include<vector>

using namespace std;

int main(void){
    int n;
    while(cin>>n){
		if(n==0) cout<<0<<endl;
		else if(n==1) cout<<1<<endl;
		else if(n==2) cout<<2<<endl;

		else{
			vector<long long> dp(n+1,0);
			dp[0]=0;
			dp[1]=1;
			dp[2]=2;
			for(int i=3; i<=n; i++){
				if(i%2){
					dp[i]=dp[i-1]%1000000000;
				}else{
					dp[i]=(dp[i/2]+dp[i-1])%1000000000;
				}
			}
			cout<<dp[n]%1000000000<<endl;
		}

    }
}
