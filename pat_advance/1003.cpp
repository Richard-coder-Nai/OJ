#include<iostream>
#include<vector>

using namespace std;

int n, m, c1, c2;
const int INF = 10005;

vector<int> teams;
vector<vector<int>> adj;

vector<vector<int>> g;

void dijstra(){
	vector<int> dist(n, INF);
	vector<bool> used(n, false);

	vector<int> nums(n, 0);
	vector<int> cnt(n, 1);

	dist[c1] = 0;
	cnt[c1] = 1;
	nums[c1] = teams[c1];
	
	for(int i=0; i<n; i++){
		int t = -1;
		int cmp = INF;
		for(int j=0; j<n; j++){
			if(used[j]==false && cmp>dist[j]){
				t = j;
				cmp = dist[j];
			}
		}
		used[t] = true;
		int d = dist[t];
		for(int j=0; j<n; j++){
			if(used[j]==false && g[t][j]!=INF){
				if(dist[t]+g[t][j]<dist[j]){
					dist[j] = dist[t] + g[t][j];
					cnt[j] = cnt[t];
					nums[j] = nums[t]+teams[j];
				}else if(dist[t] + g[t][j]==dist[j]){
					cnt[j] += cnt[t];
					nums[j] = max(nums[t]+teams[j], nums[j]);
				}
			}
		}
	}
	cout<<cnt[c2]<<" "<<nums[c2]<<endl;
}

int main(void){
	cin>>n>>m>>c1>>c2;
	teams.assign(n, 0);
	g.assign(n, vector<int>(n, INF));

	for(int i=0; i<n; i++){
		cin>>teams[i];
	}

	for(int i=0; i<m; i++){
		int x, y, w;
		cin>>x>>y>>w;
		if(x!=y){
			g[x][y] = min(g[x][y], w);
			g[y][x] = min(g[y][x], w);
		}
	}
	dijstra();
}
