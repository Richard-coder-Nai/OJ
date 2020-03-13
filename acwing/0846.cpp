#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n;
vector<vector<int>> adj;
vector<bool> visited;
int ans;

int dfs(int start){
	visited[start] = true;
	int counter = 1;
	int res = -1;
	for(auto it:adj[start]){
		if(visited[it]==false){
			int size = dfs(it);
			res = max(res, size);
			counter += size;
		}
	}
	res = max(res, n-counter);
	ans = min(res, ans);
	return counter;
}

int main(void){
	cin>>n;
	ans = n;

	adj.assign(n+1, vector<int>());
	visited.assign(n+1, false);
	for(int i=0; i<n-1; i++){
		int x, y;
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	dfs(1);

	cout<<ans;
}
