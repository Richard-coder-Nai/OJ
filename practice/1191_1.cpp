#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> adj;
vector<int> indegree;

int main(void) {
	int n;
	cin>>n;

	adj.assign(n+1, vector<int>());
	indegree.assign(n+1, 0);

	for(int i=1; i<=n; i++) {
		while(true) {
			int x;
			cin>>x;
			if(x==0) break;
			adj[i].push_back(x);
			indegree[x]++;
		}
	}

	queue<int> q;
	for(int i=1; i<=n; i++) {
		if(indegree[i]==0) {
			q.push(i);
		}
	}
	while(q.size()) {
		int front = q.front();
		cout<<front<<" ";
		q.pop();
		for(int it: adj[front]) {
			if(indegree[it]==0) continue;
			indegree[it]--;
			if(indegree[it]==0) q.push(it);
		}
	}
	cout<<endl;
}

