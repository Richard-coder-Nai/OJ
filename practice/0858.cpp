#include<iostream>
#include<vector>

using namespace std;

const int INF = 10004;

int n, m;
vector<vector<int>> g;
vector<int> dist;
vector<bool> visited;

int prim(){
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
		visited[t] = true;
		res += dist[t];
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
	dist.assign(n+1, INF);
	visited.assign(n+1, false);
	while(m--){
		int x, y, z;
		cin>>x>>y>>z;
		g[x][y] = min(g[x][y], z);
		g[y][x] = min(g[y][x], z);
	}

	int res = prim();
	if(res!=-1) cout<<res<<endl;
	else cout<<"impossible"<<endl;
}
