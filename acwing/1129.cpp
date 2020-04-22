#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e5+3;

vector<vector<int>> g;

int n, m, src, dest;

int dijstra(int src, int dest) {
	vector<int> dist(n+1, INF);
	vector<bool> used(n+1, false);
	
	dist[src] = 0;
	for(int i=0; i<n; i++) {
		int t = -1;
		int cmp = INF;
		for(int j=1; j<=n; j++) {
			if(used[j]==false && dist[j]<cmp) {
				t = j;
				cmp = dist[j];
			}
		}
		if(t==dest) return dist[dest];

		used[t] = true;
		for(int j=1; j<=n; j++) {
			if(used[j]==false && g[t][j]<INF) {
				dist[j] = min(dist[j], dist[t]+g[t][j]);
			}
		}
	}
	return dist[dest];
}

int main(void) {
	cin>>n>>m>>src>>dest;
	g.assign(n+1, vector<int>(n+1, INF));
	for(int i=0; i<m; i++){
		int x, y, z;
		cin>>x>>y>>z;
		g[x][y] = min(z, g[x][y]);
		g[y][x] = min(z, g[y][x]);
	}
	cout<<dijstra(src, dest)<<endl;
}
