#include <iostream>
#include <vector>
#include <bitset>
#include <queue>
#include <algorithm>

using namespace std;

const int N = 30010;

vector<vector<int>> adj;
bitset<N> f[N];
int n, m;

vector<int> indegree;
vector<int> path;

void topo_sort() {
	queue<int> q;
	for(int i=1; i<=n; i++) {
		if(indegree[i]==0) q.push(i);
	}
	while(q.size()) {
		int front = q.front();
		q.pop();
		path.push_back(front);
		for(int it:adj[front]) {
			if(indegree[it]>0) {
				indegree[it]--;
				if(indegree[it]==0) {
					q.push(it);
				}
			}
		}
	}
}

int main(void) {
	cin>>n>>m;
	adj.assign(n+1, vector<int>());
	indegree.assign(n+1, 0);

	for(int i=0; i<m; i++) {
		int x, y;
		cin>>x>>y;
		adj[x].push_back(y);
		indegree[y]++;
	}

	topo_sort();
	reverse(path.begin(), path.end());
	for(int it:path) {
		f[it][it] = 1;
		for(int v:adj[it]) {
			f[it] |= f[v];
		}
	}
	for(int i=1; i<=n; i++) {
		cout<<f[i].count()<<endl;
	}
}
