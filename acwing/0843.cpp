#include<iostream>

using namespace std;

const int N = 20;

char g[N][N];
bool used[N], dg[N], ndg[N];
int n;

void dfs(int u){
	if(u==n){
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				cout<<g[i][j];
			}
			cout<<endl;
		}
	}
	cout<<endl;

	for(int i=0; i<n; i++){
		if(!used[i] && !dg[u+i] && !ndg[n-u+i]){
			g[u][i] = 'Q';
			used[i] = true;
			dg[u+i] = true;
			ndg[n-u+i] = true;
			dfs(u+1);
			dg[u+i] = false;
			ndg[n-u+i] = false;
			used[i] = false;
			g[u][i] = '.';
		}
	}
}

int main(void){
	cin>>n;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			g[i][j] = '.';
		}
	}
	dfs(0);
}
