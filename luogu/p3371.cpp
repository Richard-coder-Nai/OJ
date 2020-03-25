#include<iostream>
#include<queue>

#define INF 2147483647
using namespace std;

typedef pair<int, int> PII;
vector<vector<PII>> adj;

int n, m, s;

struct cmp{
    bool operator() (PII p1, PII p2) {
		return p1.second > p2.second;
	}
};

void dijstra(int s){
	vector<int> dist(n+1, INF);
	vector<int> visitd(n+1, false);
	dist[s] = 0;
	priority_queue<PII, vector<PII>, cmp> heap;
	heap.push({s, 0});

	while(heap.size()){
		auto front = heap.top();
		heap.pop();
		int node = front.first;
		int distance = front.second;
		if(visitd[node]) continue;
		visitd[node] = true;
		//cout<<dist[node]<<endl;
		//cout<<node<<endl;
		for(auto it:adj[node]){
			int new_node = it.first;
			int new_dist = it.second;
			if(visitd[new_node]==false){
				dist[new_node]  = min(dist[new_node], dist[node]+new_dist);
				heap.push({new_node, dist[new_node]});
			}
		}
	}
	for(int i=1; i<=n; i++) cout<<dist[i]<<" ";
	cout<<endl;
}

int main(void){
	cin>>n>>m>>s;
	adj.assign(n+1, vector<pair<int, int>>());
	for(int i=0; i<m; i++){
		int x, y, z;
		cin>>x>>y>>z;
		adj[x].push_back({y, z});
	}
	dijstra(s);
}
