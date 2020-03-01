#include<iostream>

using namespace std;

int f[10005][10005];
int g[10005][10005];

int r, c;
int maxlen = -1;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

int dfs(int x, int y){
	if(f[x][y]!=0) return f[x][y];
	else{
		for(int i=0; i<4; i++){
			if(x+dx[i]>=0 && x+dx[i]<r && y+dy[i]>=0 && y+dy[i]<c && g[x][y]>g[x+dx[i]][y+dy[i]]){
				f[x][y] = max(f[x][y], 1+dfs(x+dx[i], y+dy[i]));
			}
		}
	}
	return f[x][y];
}

int main(void){
	cin>>r>>c;
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			cin>>g[i][j];
		}
	}
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			int len = dfs(i, j);
			maxlen = max(maxlen, len);
		}
	}
	cout<<maxlen+1<<endl;
}
