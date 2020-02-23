#include<iostream>
#include<vector>

using namespace std;

const int N = 1005;

int volume[N];
int cost[N];

int main(void){
	int n, m;
	cin>>n>>m;

	vector<int> dp(m+1, 0);
	for(int i=0; i<n; i++){
		int v, c;
		cin>>v>>c;
		volume[i] = v;
		cost[i] = c;
		//dp[v] = c;
	}

	for(int i=0; i<=m; i++){
		for(int j=0; j<n; j++){
			if(i-volume[j]>=0 && dp[i-volume[j]]+cost[j]>dp[i]){
				dp[i] = dp[i-volume[j]]+cost[j];
			}
		}
	}

	cout<<dp[m];
}

