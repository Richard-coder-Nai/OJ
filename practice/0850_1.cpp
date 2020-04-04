#include<iostream>
#include<vector>
#include<queue>

using namespace std;

typedef pair<int, int> PII;

int n, m;
const int INF = 1e5;

vector<vector<PII>> adj;

void dijstra(){
	vector<int> dist(n+1, INF);
	vector<bool> used(n+1, false);
	priority_queue<PII, vector<PII>, greater<PII>> q;
	q.push({0, 1});

	while(q.size()){
		auto top = q.top();
		q.pop();
		int w = top.first;
		int node = top.second;
		if(used[node]) continue;
		used[node] = true;
		for(auto it:adj[node]){
			int new_node = it.second;
			int new_w = it.first;
			if(used[new_node]==false && dist[new_node]>new_w+w){
				dist[new_node] = new_w + w;
				q.push({dist[new_node], new_node});
			}
		}
	}
	if(dist[n]==INF) cout<<"-1"<<endl;
	else cout<<dist[n]<<endl;
}

int main(void){
	cin>>n>>m;
	adj.assign(n+1, vector<PII>());
	for(int i=0; i<m; i++){
		int x, y, z;
		cin>>x>>y>>z;
		if(x!=y){
			adj[x].push_back({z, y});
		}
	}
	dijstra();
}
