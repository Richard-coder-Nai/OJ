#include<iostream>

using namespace std;

int g[55][55]

int main(void){
	int n,m;
	cin>>m>>n;

	for(int i=1; i<=m; i++){
		for(int j=1; j<=n; j++){
			cin>>g[i][j];
		}
	}

	//step 1
	int counter = 0;
	vector<vector<int>> dp(m+2, vector<int>(n+2, 0));
	for(int i=1; i<=m; i++){
		for(int j=1; j<=n; j++){
			dp[i][j] = g
		}
	}
		

}
