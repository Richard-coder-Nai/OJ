#include<iostream>
#include<vector>

using namespace std;

const int INF = 1e4+5;


vector<vector<int>> g;
vector<int> dist;
vector<bool> visited;
int n, m;

int dijsktra(){
	dist[1] = 0;
	for(int i=0; i<n; i++){
		int t = -1;
		int cmp = INF;
		for(int j=1; j<=n; j++){
			if(visited[j]==false && cmp>dist[j]){
				cmp = dist[j];
				t = j; 
			}
		}
		if(t==-1) return -1;
		visited[t] = true;

		for(int j=1; j<=n; j++){
			if(visited[j]==false && g[t][j]!=INF){
				dist[j] = min(dist[j], dist[t]+g[t][j]);
			}
		}
	}
	return dist[n];
}

int main(void){
	cin>>n>>m;
	g.assign(n+1, vector<int>(n+1, INF));
	dist.assign(n+1, INF);
	visited.assign(n+1, false);

	for(int i=0; i<m; i++){
		int x, y, z;
		cin>>x>>y>>z;
		g[x][y] = min(g[x][y], z);
	}
	cout<<dijsktra()<<endl;
}
