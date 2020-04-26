#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<vector<int>> adj;
vector<int> indegree;

int main(void) {
	cin>>n>>m;
	adj.assign(n+1, vector<int>());
	indegree.assign(n+1, 0);
	for(int i=1; i<=m; i++) {
		int x, y;
		cin>>x>>y;
		adj[y].push_back(x);
		indegree[x]++;
	}

	queue<int> q;
	for(int i=1; i<=n; i++) {
		if(indegree[i]==0) {
			q.push(i);
		}
	}
	int res = 0;
	int cost = 100;
	int cnt = 0;
	while(q.size()) {
		int size = q.size();
		cnt += size;
		res += (cost*size);
		for(int i=0; i<size; i++) {
			int front = q.front();
			q.pop();
			for(int it:adj[front]) {
				if(indegree[it]>0) {
					indegree[it]--;
					if(indegree[it]==0) {
						q.push(it);
					}
				}
			}
		}
		cost++;
	}

	if(cnt==n) 
		cout<<res<<endl;
	else
		cout<<"Poor Xed"<<endl;
}
