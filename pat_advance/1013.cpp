#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include<cstdio>
#include<cstring>

using namespace std;

vector<int> adj[1111];
bool visited[1111];

int del_city;

void dfs(int v){
	if(v==del_city) return;

	visited[v] = true;
	for(int i=0; i<adj[v].size(); i++){
		int it = adj[v][i];
		if(visited[it]==false){
			dfs(it);
		}
	}
	return;
}

void bfs(int v){
	if(v==del_city) return;
	queue<int> q;
	q.push(v);
	visited[v] = true;

	while(!q.empty()){
		int front=q.front();
		q.pop();
		visited[front]=true;
		for(int i=0; i<adj[front].size(); i++){
			int it = adj[front][i];
			if(it!=del_city&&visited[it]==false){
				q.push(it);
			}
		}
	}
}

int main(void){
	int n,e,k;
	cin>>n>>e>>k;


	//adj.assign(n, list<int>());

	for(int i=0; i<e; i++){
		int n1, n2;
		cin>>n1>>n2;
		n1--;
		n2--;
		adj[n1].push_back(n2);
		adj[n2].push_back(n1);
	}

	for(int i=0; i<k; i++){
		cin>>del_city;
		del_city--;
		//visited.assign(n, false);
		memset(visited, false, sizeof(visited));

		int block=0;
		for(int j=0; j<n; j++){
			if(j!=del_city&&visited[j]==false){
				bfs(j);
				block++;
			}
		}
		cout<<block-1<<endl;
	}
}
