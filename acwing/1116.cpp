#include<iostream>

using namespace std;

int t;
int m, n, x, y;

int g[15][15];
int res = 0;

int dx[8]={1,1,2,2,-2,-2,-1,-1};
int dy[8]={2,-2,1,-1,1,-1,2,-2};

void dfs(int x, int y, int counter){
	if(counter==m*n){
		res++;
		return;
	}
	g[x][y] = 1;
	for(int i=0; i<8; i++){
		int nx = x+dx[i];
		int ny = y+dy[i];
		if(nx>=0 && nx<n && ny>=0 && ny<m && g[nx][ny]==0){
			dfs(nx, ny, counter+1);
		}
	}
	g[x][y] = 0;
}

int main(void){
	cin>>t;
	while(t--){
		cin>>n>>m>>x>>y;
		dfs(x, y, 1);
		cout<<res<<endl;
		res = 0;
	}
}
