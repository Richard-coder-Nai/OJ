#include<iostream>
#include<vector>
#include<queue>

using namespace std;

const int INF = 1e7+4;

int n, m;
typedef pair<int, int> PII;
vector<vector<PII>> adj;

bool spfa() {
	vector<int> dist(n+1, 0);
	vector<bool> used(n+1, true);
	vector<int> cnt(n+1, 0);
	queue<int> q;
	for(int i=1; i<=n; i++){
		q.push(i);
	}

	while(q.size()){
		int front = q.front();
		q.pop();
		used[front] = false;
		for(auto it:adj[front]){
			int node = it.first;
			int w = it.second;
			if(dist[node]>dist[front]+w){
				dist[node] = dist[front]+w;
				cnt[node] = cnt[front]+1;
				if(cnt[node]>=n) return true;
				if(used[node]==false){
					used[node] = true;
					q.push(node);
				}
			}
		}
	}
	return false;
}

int main(void) {
	cin>>n>>m;
	adj.assign(n+1, vector<PII>());
	for(int i=0; i<m; i++){
		int x, y, z;
		cin>>x>>y>>z;
		adj[x].push_back({y, z});
	}
	if(spfa()){
		cout<<"Yes"<<endl;
	}
	else{
		cout<<"No"<<endl;
	}
}
