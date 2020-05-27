#include<iostream>

using namespace std;

int dx[8]={1,0,-1,0,1,-1,1,-1};
int dy[8]={0,1,0,-1,1,-1,-1,1};

char g[1005][1005];

int n, m;

void dfs(int x, int y){
	g[x][y] = '.';
	for(int i=0; i<8; i++){
		if(g[x+dx[i]][y+dy[i]]=='W'){
			dfs(x+dx[i], y+dy[i]);
		}
	}
}

int main(void){
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			cin>>g[i][j];
		}
	}

	int res = 0;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			if(g[i][j]=='W'){
				dfs(i, j);
				res++;
			}
		}
	}
	cout<<res<<endl;
}
