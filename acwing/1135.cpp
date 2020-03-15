#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstdio>

#define INT_MAX 2147483647

using namespace std;

const int INF = 100005;

typedef pair<int, int> PII;

struct cmp{
    bool operator() (PII a, PII b) {
		return a.first < b.first;
	}
};


vector<vector<PII>> adj;
int n, m;

vector<int> tmp;
vector<int> used(5, false);
vector<int> family(5, 0);
vector<vector<int>> path;

void dfs(){
	if(tmp.size()==5){
		path.push_back(tmp);
		return;
	}
	for(int i=0; i<5; i++){
		if(used[i]==false){
			used[i] = true;
			tmp.push_back(family[i]);
			dfs();
			tmp.pop_back();
			used[i] = false;
		}
	}
}


int dijstra(int src, int dest){
	vector<int> dist(n+1, INF);
	vector<bool> visited(n+1, false);
	dist[src] = 0;
	priority_queue<PII, vector<PII>, cmp> heap;
	heap.push({0, src});
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
	return dist[dest];
}

int main(void){
	cin>>n>>m;
	adj.resize(n+1);
	for(int i=0; i<5; i++){
		cin>>family[i];
	}

	for(int i=0; i<m; i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if(a!=b){
			adj[a].push_back({b, c});
			adj[b].push_back({a, c});
		}
	}
	dfs();

	int res = INT_MAX;

	for(auto it:path){
		int tmp_dist = dijstra(1, it[0]);
		for(int i=0; i<4; i++){
			tmp_dist += dijstra(it[i], it[i+1]);
		}
		res = min(res, tmp_dist);
	}
	cout<<res<<endl;
}
