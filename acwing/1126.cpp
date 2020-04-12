#include<iostream>
#include<vector>

using namespace std;

const int INF = 1e4+4;

int n, m;
int src, dest;
vector<vector<double>> g;
vector<bool> used;
vector<double> dist;

double dijsktra(int src, int dest){
	dist[src] = 100.0;
	for(int i=0; i<n; i++){
		int t = -1;
		int cmp = INF;
		for(int j=1; j<=n; j++){
			if(dist[j]<cmp && used[j]==false){
				cmp = dist[j];
				t = j;
			}
		}
		if(t==dest) return dist[dest];
		if(t==-1) return -1;
		used[t] = true;
		for(int j=1; j<=n; j++){
			if(used[j]==false && g[t][j]!=INF){
				dist[j] = min(dist[j], dist[t]/g[t][j]);
			}
		}
	}
	return dist[dest];
}

int main(void){
	cin>>n>>m;
	dist.assign(n+1, INF);
	used.assign(n+1, false);
	g.assign(n+1, vector<double>(n+1, INF));
	for(int i=0; i<m; i++){
		int x, y, z;
		cin>>x>>y>>z;
		if(x!=y){
			g[x][y] = min(g[x][y], (100.0-z)/100.0);
			g[y][x] = min(g[y][x], (100.0-z)/100.0);
		}
	}
	cin>>src>>dest;
	double res = dijsktra(src, dest);
	printf("%.8f\n", res);
}
