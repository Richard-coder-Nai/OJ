#include<iostream>

using namespace std;

int v[105], w[105], s[105];
int f[105][105];

int main(void){
	int n, m;
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		cin>>v[i]>>w[i]>>s[i];
	}

	for(int i=1; i<=n; i++){
		for(int j=0; j<=m; j++){
			for(int k=0; k<=s[i] && k*v[i]<=j; k++){
				f[i][j] = max(f[i][j], f[i-1][j-v[i]*k]+w[i]*k);
			}
		}
	}
	cout<<f[n][m]<<endl;
}
