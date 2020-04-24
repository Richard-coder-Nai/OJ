#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e5+3;
int n, m;

vector<vector<int>> g;

int dijstra() {
	vector<int> dist(n+1, INF);
	vector<bool> used(n+1, false);
	dist[1] = 0;

	for(int i=0; i<n; i++) {
		int t = -1;
		int cmp = INF;
		for(int j=1; j<=n; j++) {
			if(used[j]==false && dist[j]<cmp) {
				t = j;
				cmp = dist[j];
			}
		}
		if(t==-1) return -1;
		used[t] = true;

		for(int j=1; j<=n; j++) {
			if(used[j]==false && g[t][j]!=INF) {
				dist[j] = min(dist[j], dist[t]+g[t][j]);
			}
		}
	}

	int res = 0;
	for(int i=1; i<=n; i++) {
		res = max(res, dist[i]);
	}
	return res;
}


int main(void) {
	cin>>n>>m;
	g.assign(n+1, vector<int>(n+1, INF));
	for(int i=0; i<m; i++) {
		int x, y, z;
		cin>>x>>y>>z;
		if(x!=y) {
			g[x][y] = min(g[x][y], z);
			g[y][x] = min(g[y][x], z);
		}
	}
	cout<<dijstra()<<endl;
}
	
