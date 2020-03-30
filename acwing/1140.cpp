#include<iostream>
#include<vector>

using namespace std;

const int INF = 100005;
vector<vector<int>> g;
vector<int> dist;
vector<bool> used;
int n, tmp;

int prim(){
	dist[1] = 0;
	int res = 0;
	for(int i=0; i<n; i++){
		int t = -1;
		int cmp = INF;
		for(int j=1; j<=n; j++){
			if(used[j]==false && cmp>dist[j]){
				t = j;
				cmp = dist[j];
			}
		}
		used[t] = true;
		res += dist[t];
		for(int j=1; j<=n; j++){
			if(used[j]==false && g[t][j]!=INF){
				dist[j] = min(dist[j], g[t][j]);
			}
		}
	}
	return res;
}

int main(void) {
	cin>>n;
	g.assign(n+1, vector<int>(n+1, INF));
	used.assign(n+1, false);
	dist.assign(n+1, INF);
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			cin>>tmp;
			if(tmp){
				g[i][j] = tmp;
			}
		}
	}
	cout<<prim()<<endl;
}
