#include<iostream>

using namespace std;

int f[10005][10005];
int volume[10005], value[10005];
int n, m;

int main(void){
	cin>>n>>m;

	for(int i=1; i<=n; i++){
		cin>>volume[i]>>value[i];
	}

	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			f[i][j] = f[i-1][j];
			if(j>=volume[i]){
				f[i][j] = max(f[i][j], f[i-1][j-volume[i]]+value[i]);
			}
		}
	}
	cout<<f[n][m];
}
