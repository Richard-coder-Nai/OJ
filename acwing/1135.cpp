#include<iostream>
#include<vector>
#include<algorithm>
#include<map>


using namespace std;

const int INF = 1005;
const int  INT_MAX = 214748364;
int n, m;
int a, b, c, d, e;
vector<int> family(5, 0);
vector<vector<int>> p;

vector<int> path;
vector<bool> used(5, false);

void dfs(){
	if(path.size()==5){
		p.push_back(path);
		return;
	}
	for(int i=0; i<5; i++){
		if(used[i]==false){
			used[i] = true;
			path.push_back(family[i]);
			dfs();
			path.pop_back();
			used[i] = false;
		}
	}
	return;
}

int dijskra(vector<vector<int>> g, int src, int dest){
	vector<int> dist(n+1, INF);
	vector<bool> visited(n+1, false);
    dist[src] = 0;
    for (int i = 0; i < n; i++){
		int t = -1;
        int cmp = INF;
        for (int j = 1; j <= n; j++){
            if (visited[j] == false && dist[j] < cmp)
            {
                t = j;
                cmp = dist[j];
            }
        }
        if (t == -1)
            return -1;
        visited[t] = true;
        for (int j = 1; j <= n; j++)
        {
            if (g[t][j] != INF)
            {
                dist[j] = min(dist[j], dist[t] + g[t][j]);
            }
        }
		if(t==dest) return dist[dest];
    }
    return dist[n];
}

int main(void){
	cin>>n>>m;
	vector<vector<int>> g(n+1, vector<int>(n+1, INF));

	for(int i=0; i<5; i++) cin>>family[i];
	dfs();

	for(int i=0; i<=n; i++){
		for(int j=0; j<=n; j++){
			if(i==j) g[i][j] = 0;
			else g[i][j] = INF;
		}
	}
	
	for(int i=0; i<m; i++){
		int x, y, t;
		cin>>x>>y>>t;
		g[x][y] = t;
		g[y][x] = t;
	}

	for(int i=0; i<5 ;i++){
		int dist = dijskra(g, 1, family[i]);
		g[1][family[i]] = dist;
		g[family[i]][1] = dist;
	}
	for(int i=0; i<4; i++){
		for(int j=i+1; j<5; j++){
			int dist = dijskra(g, family[i], family[j]);
			g[family[i]][family[j]] = dist;
			g[family[j]][family[i]] = dist;
		}
	}

	int res = INT_MAX;
	for(auto it:p){
		int dist = g[1][it[0]];
		for(int i=1; i<5; i++){
			dist += g[it[i-1]][it[i]];
		}
		res = min(res, dist);
	}
	cout<<res<<endl;
}
