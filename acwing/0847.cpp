#include<iostream>
#include<queue>
#include<vector>

using namespace std;

vector<vector<int>> adj;
vector<int> dist;
vector<bool> visited;

int main(void){
	int n,m;
	cin>>n>>m;
	adj.assign(n, vector<int>());
	dist.assign(n, -1);
	visited.assign(n, false);

	for(int i=0; i<m; i++){
		int src, dest;
		cin>>src>>dest;
		src--;
		dest--;
		adj[src].push_back(dest);
	}

	queue<int> q;
	q.push(0);
	visited[0] = true;
	int counter = 0;

	while(!q.empty()){
		int size = q.size();
		for(int i=0; i<size; i++){
			int front = q.front();
			q.pop();
			dist[front] = counter;
			for(auto it:adj[front]){
				if(visited[it]==false){
					q.push(it);
					visited[it] = true;
				}
			}
		}
		counter++;
	}
	cout<<dist[n-1]<<endl;
}

