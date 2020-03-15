#include<iostream>
#include<vector>
#include<queue>

using namespace std;

typedef pair<int, int> PII;
const int INF = 1000005;

vector<vector<PII>> adj;
vector<int> dist;
vector<bool> visited;
int n, m;

struct cmp{
    bool operator() (PII a, PII b) {
		return a.first< b.first;
	}
};

int dijstra(){
	dist[1] = 0;
	priority_queue<PII, vector<PII>, cmp> heap;
	heap.push({0, 1});
	while(heap.size()){
		auto top = heap.top();
		heap.pop();
		int distance = top.first;
		int node = top.second;
		if(visited[node]) continue;
		visited[node] = true;
		dist[node] = distance;
		for(auto it:adj[node]){
			int new_node = it.first;
			int w = it.second;
			if(dist[new_node]==INF || dist[new_node]>dist[node]+w){
				dist[new_node] = dist[node]+w;
				heap.push({dist[new_node], new_node});
			}
		}
	}
	if(dist[n]!=INF) return dist[n];
	else return -1;
}


int a, b, c;
int main(void){
	cin>>n>>m;
	adj.assign(n+1, vector<PII>());
	dist.assign(n+1, INF);
	visited.assign(n+1, false);

	for(int i=0; i<m; i++){
		scanf("%d %d %d", &a, &b, &c);
		if(a!=b){
			adj[a].push_back({b, c});
		}
	}
	int res = dijstra();
	cout<<res<<endl;
}
