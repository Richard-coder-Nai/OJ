#include<iostream>
#include<vector>

using namespace std;


const int INF = 1e5+3;

vector<vector<int>> g;

int n, m;

void prim() {
	vector<int> dist(n+1, INF);
	vector<bool> visited(n+1, false);
	int res = 0;
	dist[1] = 0;

	for(int i=0; i<n; i++) {
		int t = -1;
		int cmp = INF;
		for(int j=1; j<=n; j++) {
			if(visited[j]==false && cmp>dist[j]) {
				t = j;
				cmp = dist[j];
			}
		}
		if(t==-1){
			cout<<"impossible"<<endl;
			return;
		}
		visited[t] = true;
		res += dist[t];

		for(int j=1; j<=n; j++) {
			if(visited[j]==false && g[t][j]!=INF) {
				dist[j] = min(dist[j], g[t][j]);
			}
		}
	}

	cout<<res<<endl;
}

int main(void) {
	cin>>n>>m;
	g.assign(n+1, vector<int>(n+1, INF));
	for(int i=0; i<m; i++){
		int x, y, z;
		cin>>x>>y>>z;
		if(x!=y){
			g[x][y] = min(g[x][y], z);
			g[y][x] = min(g[y][x], z);
		}
	}
	
	prim();
}
