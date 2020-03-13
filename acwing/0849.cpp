#include<iostream>
#include<vector>

const int INF = 10005;

using namespace std;

int n, m;
vector<vector<int>> g;
vector<bool> visited;
vector<int> dist;

int dijskra(){
	dist[1] = 0;

	for(int i=0; i<n; i++){
		int t = -1;
		int cmp = INF;
		for(int j=1; j<=n; j++){
			if(visited[j]==false && dist[j]<cmp){
				t = j;
				cmp = dist[j];
			}
		}
		if(t == -1) return -1;

		visited[t] = true;

		for(int j=1; j<=n; j++){
			if(g[t][j]!=INF){
				dist[j] = min(dist[j], dist[t]+g[t][j]);
			}
		}
	}
	return dist[n];
}

int main(void){
	cin>>n>>m;
	g.assign(n+1, vector<int>(n+1, INF));
	visited.assign(n+1, false);
	dist.assign(n+1, INF);

	for(int i=0; i<m; i++){
		int x, y, z;
		cin>>x>>y>>z;
		g[x][y] = min(z, g[x][y]);
	}

	cout<<dijskra()<<endl;

}
