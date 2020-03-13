#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n;
vector<vector<int>> adj;
vector<int> indegree;
vector<int> path;


int main(void){
	cin>>n;
	adj.assign(n+1, vector<int>());
	indegree.assign(n+1, 0);

	int x;
	for(int i=1; i<=n; i++){
		while(true){
			cin>>x;
			if(x==0) break;
			adj[i].push_back(x);
			indegree[x]++;
		}
	}

	queue<int> q;
	for(int i=1; i<=n; i++){
		if(indegree[i]==0) 
			q.push(i);
	}

	while(!q.empty()){
		int front = q.front();
		path.push_back(front);
		q.pop();
		for(auto it:adj[front]){
			if(indegree[it]>0){
				indegree[it]--;
				if(indegree[it]==0){
					q.push(it);
				}
			}
		}
	}

	for(auto it:path){
		cout<<it<<" ";
	}
	cout<<endl;
}

