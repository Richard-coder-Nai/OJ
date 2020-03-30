#include<iostream>
#include<vector>

using namespace std;

const int INF = 10010;
typedef pair<int, int> PII;

int n, m, src, dest;
vector<int> dist;
vector<int> pre;
vector<int> cost;
vector<bool> used;
vector<vector<PII>> g;

void dijstra(int scr, int dest){
	dist[src] = 0;
	cost[src] = 0;
	for(int i=0; i<n; i++){
		int t = -1;
		int cmp = INF;
		for(int j=0; j<n; j++){
			if(used[j]==false && cmp>dist[j]){
				t = j;
				cmp = dist[j];
			}
		}
		used[t] = true;
		for(int j=0; j<n; j++){
			int distance = g[t][j].first;
			int c = g[t][j].second;
			if(used[j]==false && distance!=INF){
				if(dist[j]>dist[t]+distance){
					dist[j] = dist[t] + distance;
					cost[j] = cost[t] + c;
					pre[j] = t;
				}
				if(dist[j]==dist[t]+distance){
					dist[j] = dist[t]+distance;
					if(c+cost[t]<cost[j]){
						cost[j] = c + cost[t];
						pre[j] = t;
					}
				}
			}
		}
	}
}

void dfs(int x){
	if(x==src){
		cout<<src<<" ";
		return;
	}
	dfs(pre[x]);
	cout<<x<<" ";
}

int main(void){
	cin>>n>>m>>src>>dest;
	g.assign(n, vector<PII>(n, {INF, INF}));
	dist.assign(n, INF);
	used.assign(n, false);
	cost.assign(n, INF);
	pre.assign(n, -1);
	for(int i=0; i<m; i++){
		int x, y, z, w;
		cin>>x>>y>>z>>w;
		g[x][y] = {z, w};
		g[y][x] = {z, w};
	}
	dijstra(src, dest);
	dfs(dest);
	cout<<dist[dest]<<" "<<cost[dest]<<endl;
	return 0;
}
