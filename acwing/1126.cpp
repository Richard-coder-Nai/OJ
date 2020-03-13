#include<iostream>
#include<vector>

using namespace std;

const int INF = 1e4+4;

int n, m;
vector<vector<int>> g;
vector<bool> used;
vector<int> dist;

int dijsktra(){
	dist[1] = 0;
	for(int i=0; i<n; i++){
		int t = -1;
		int cmp = INF;
		for(int j=1; j<=n; j++){
			if(dist[j]<cmp && used[j]==false){
				cmp = dist[j];
				t = j;
			}
		}
		if(t==-1) return -1;
		used[t] = true;
		for(int j=1; j<=n; j++){
			if(used[j]==false && g[t][j]!=INF){
				dist[j] = min(dist[j], dist[t]+g[t][j]);
			}
		}
	}
	return dist[n];
}

int main(void){
	cin>>n>>m;
	dist.assign(n+1, INF);
	used.assign(n+1, false);
	g.assign(n+1, vector<int>(n+1, INF));
	for(int i=0; i<m; i++){
		int x, y, z;
		cin>>x>>y>>z;
		g[x][y] = min(g[x][y], z);
	}

	cout<<dijsktra()<<endl;
}
