#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n, m;
int x, y, z;
const int INF = 100005;

typedef pair<int, int> PII;
vector<int> dist;
vector<bool> used;
vector<vector<PII>> adj;

int dijstra(){
	dist[1] = 0;
	priority_queue<PII, vector<PII>, greater<PII>> heap;
	heap.push({dist[1], 1});
	while(heap.size()){
		auto top = heap.top();
		heap.pop();
		int distance = top.first;
		int node = top.second;
		if(used[node]) continue;
		dist[node] = distance;
		used[node] = true;
		for(auto it:adj[node]){
			heap.push({it.first+distance, it.second});
		}
	}

	if(dist[n]==INF) return -1;
	return dist[n];
}


int main(void){
	cin>>n>>m;
	adj.assign(n+1, vector<PII>());
	used.assign(n+1, false);
	dist.assign(n+1, INF);
	for(int i=0; i<m; i++){
		cin>>x>>y>>z;
		adj[x].push_back({z, y});
	}
	cout<<dijstra()<<endl;
}
