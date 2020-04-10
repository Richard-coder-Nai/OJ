#include<iostream>
#include<vector>
#include<queue>

using namespace std;

const int INF = 1e6+3;

typedef pair<int,int> PII;
int n, m;
vector<vector<PII>> adj;

void sfpa(){
	vector<int> dist(n+1, INF);
	vector<bool> used(n+1, false);
	queue<int> q;
	dist[1] = 0;
	used[1] = true;
	q.push(1);

	while(q.size()){
		int t = q.front();
		q.pop();
		used[t] = false;
		for(auto it:adj[t]){
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
	if(dist[n]!=INF){
		cout<<dist[n]<<endl;
	}else{
		cout<<"impossible"<<endl;
	}
}

int main(void) {
	cin>>n>>m;
	adj.assign(n+1, vector<PII>());
	for(int i=0; i<m; i++){
		int x, y, z;
		cin>>x>>y>>z;
		if(x!=y){
			adj[x].push_back({y, z});
		}
	}
	sfpa();
}
