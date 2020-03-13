#include<iostream>

using namespace std;

const int N = 1005;

int n, m;
int f[N][N];

int v[N];
int c[N];


int main(void){
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		cin>>v[i];
		cin>>c[i];
	}

	for(int i=1;i<=n; i++){
		for(int j=1; j<=m; j++){
			f[i][j] = f[i-1][j];
			if(j>=v[i]){
				f[i][j] = max(f[i][j], f[i-1][j-v[i]]+c[i]);
			}
		}
	}

	cout<<f[n][m]<<endl;
}
