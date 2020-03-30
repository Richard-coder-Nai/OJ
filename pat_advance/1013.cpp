#include<iostream>
#include<vector>


using namespace std;

vector<int> adj[1005];
vector<bool> used;

int n, m, k;
int curPoint;

void dfs(int x){
	if(x==curPoint) return;
	if(used[x]==true) return;

	used[x] = true;

	for(int it:adj[x]){
		if(used[it]==false)
			dfs(it);
	}
}

int main(void){
	scanf("%d%d%d", &n ,&m, &k);

	for(int i=0; i<m; i++){
		int x, y;
		scanf("%d%d", &x ,&y);
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	while(k--){
		used.assign(n+1, false);
		scanf("%d", &curPoint);
		used[curPoint] = true;
		int res = 0;
		for(int i=1; i<=n; i++){
			if(used[i]==false){
				res++;
				dfs(i);
			}
		}
		cout<<res-1<<endl;
	}
}
