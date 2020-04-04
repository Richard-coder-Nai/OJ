#include<iostream>
#include<vector>
#include<queue>

using namespace std;

const int INF = 1e5;

typedef pair<int, int> PII;
vector<vector<PII>> adj;
int n, m;

void spfa(){
	vector<int> dist(n+1, INF);
	vector<bool> used(n+1, false);
	queue<int> q;

	q.push(1);
	used[1] = true;
	dist[1] = 0;

	while(q.size()){
		int t = q.front();
		q.pop();
		used[t] = false;
		for(auto it: adj[t]){
			int node = it.first;
			int w = it.second;
			if(dist[node]>dist[t]+w){
				dist[node] = dist[t]+w;
				if(used[node]==false){
					q.push(node);
					used[node] = true;
				}
			}
		}
	}

	if(dist[n]==INF){
		cout<<"impossible"<<endl;
	}
	else{
		cout<<dist[n]<<endl;
	}
}

int main(void){
	cin>>n>>m;
	adj.assign(n+1, vector<PII>());
	for(int i=0; i<m; i++){
		int x, y, z;
		cin>>x>>y>>z;
		if(x!=y) adj[x].push_back({y, z});
	}
	spfa();
}
