#include<iostream>

using namespace std;

int g[105][105];
int f[105][105];
int n;


int main(void){
	cin>>n;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			cin>>g[i][j];
		}
	}

	for(int i=1; i<=n; i++){
		f[i][1] = g[i][1]+f[i-1][1];
	}

	for(int i=1; i<=n; i++){
		f[1][i] = g[1][i]+f[1][i-1];
	}
	
	for(int i=2; i<=n; i++){
		for(int j=2; j<=n; j++){
			f[i][j] = g[i][j]+min(f[i-1][j], f[i][j-1]);
		}
	}

	cout<<f[n][n]<<endl;
}
