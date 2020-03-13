#include<iostream>
#include<string>
#include<vector>
#include<queue>

using namespace std;

int g[1005][1005];
int res[1005][1005];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int n, m;

int main(void){
	cin>>n>>m;
	queue<pair<int, int>> q;

	for(int i=0; i<n; i++){
		string tmp;
		cin>>tmp;
		for(int j=0; j<m; j++){
			g[i][j] = tmp[j]-'0';
			if(g[i][j]==1){
				q.push(make_pair(i, j));
			}
		}
	}

	int deep = 0;
	while(!q.empty()){
		int size = q.size();
		while(size--){
			auto front = q.front();
			q.pop();
			int x = front.first;
			int y = front.second;
			res[x][y] = deep;
			for(int i=0; i<4; i++){
				int nx = x+dx[i];
				int ny = y+dy[i];
				if(nx>=0 && ny>=0 && nx<n && ny<m && g[nx][ny]==0){
					g[nx][ny] = -1;
					q.push(make_pair(nx, ny));
				}
			}
		}
		deep++;
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cout<<res[i][j]<<" ";
		}
		cout<<endl;
	}
}
