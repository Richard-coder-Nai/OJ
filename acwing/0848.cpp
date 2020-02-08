#include<iostream>
#include<vector>
#include<queue>
#include<list>

using namespace std;

int main(void){
	int n, m;
	cin>>n>>m;

	vector<list<int>> adj;
	adj.assign(n+1, list<int>());
	vector<int> indegree(n+1, 0);


	for(int i=0; i<m; i++){
		int src, dest;
		cin>>src>>dest;
		adj[src].push_back(dest);
		indegree[dest]++;
	}

	queue<int> q;
	for(int i=1; i<=n; i++){
		if(indegree[i]==0){
			q.push(i);
		}
	}

	vector<int> topo;
	int front;
	while(!q.empty()){
		front = q.front();
		topo.push_back(front);
		q.pop();

		for(auto it: adj[front]){
			indegree[it]--;
			if(indegree[it]==0)
				q.push(it);
		}
	}

	if(topo.size()!=n) cout<<"-1"<<endl;
	else{
		bool first = true;
		for(auto it: topo){
			if(first == false) cout<<" ";
			cout<<it;
			first = false;
		}
		cout<<endl;
	}
	
}
