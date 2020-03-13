#include<iostream>
#include<vector>

using namespace std;

const int INF = 10005;

int n, m;

vector<vector<int>> g;
vector<int> dist;
vector<bool> visited;

int prime(){
	dist[1] = 0;
	int res = 0;
	for(int i=0; i<n; i++){
		int t = -1;
		int cmp = INF;
		for(int j=1; j<=n; j++){
			if(visited[j]==false && cmp>dist[j]){
				t = j;
				cmp = dist[j];
			}
		}
		if(t==-1) return -1;
		res += dist[t];
		visited[t] = true;
		for(int j=1; j<=n; j++){
			if(visited[j]==false && g[t][j]!=INF){
				dist[j] = min(dist[j], g[t][j]);
			}
		}
	}
	return res;
}

int main(void){
	cin>>n>>m;

	g.assign(n+1, vector<int>(n+1, INF));
	visited.assign(n+1, false);
	dist.assign(n+1, INF);
	for(int i=0; i<m; i++){
		int x, y, z;
		cin>>x>>y>>z;
		g[x][y] = min(g[x][y], z);
		g[y][x] = min(g[y][x], z);
	}

	int res = prime();
	if(res==-1) cout<<"impossible"<<endl;
	else cout<<res<<endl;
}
