#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e6+3;


int n, m;

void dijstra() {
	vector<int> dist(n+1, INF);
	vector<int> cost(n+1, INF);
	vector<bool> used(n+1, false);

	vector<vector<int>> g(n+1, vector<int>(n+1, INF));
	vector<vector<int>> cg(n+1, vector<int>(n+1, INF));

	for(int i=0; i<m; i++) {
		int x, y, z, w;
		cin>>x>>y>>z>>w;
		g[x][y] = z;
		g[y][x] = z;
		cg[x][y] = w;
		cg[y][x] = w;
	}

	int src, dest;
	cin>>src>>dest;

	dist[src] = 0;
	cost[src] = 0;

	for(int i=0; i<n; i++) {
		int t = -1;
		int cmp = INF;
		for(int j=1; j<=n; j++) {
			if(used[j]==false && cmp>dist[j]) {
				t = j;
				cmp = dist[j];
			}
		}

		used[t] = true;

		for(int j=1; j<=n; j++) {
			if(used[j]==false && g[t][j]!=INF) {
				if(dist[j]==dist[t]+g[t][j]) {
					cost[j] = min(cost[j], cost[t]+cg[t][j]);
				}
				if(dist[j]>=dist[t]+g[t][j]) {
					dist[j] = dist[t]+g[t][j];
					cost[j] = cost[t]+cg[t][j];
				}
			}
		}
	}

	cout<<dist[dest]<<" "<<cost[dest]<<endl;
}

int main(void) {
	while(true) {
		cin>>n>>m;
		if(n==0 && m==0) return 0;
		dijstra();
	}
}
