#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e5+5;
vector<vector<int>> g;

int n;

int prime() {
	vector<int> dist(n+1, INF);
	vector<int> used(n+1, false);
	dist[0] = 0;
	int res = 0;
	for(int i=0; i<=n; i++) {
		int t = -1;
		int cmp = INF;
		for(int j=0; j<=n; j++) {
			if(used[j]==false && dist[j]<cmp) {
				cmp = dist[j];
				t = j;
			}
		}
		used[t] = true;
		res += dist[t];
		for(int j=0; j<=n; j++) {
			if(used[j]==false && g[t][j]!=INF) {
				dist[j] = min(dist[j], g[t][j]);
			}
		}
	}

	return res;
}
int main(void) {
	cin>>n;
	g.assign(n+1, vector<int>(n+1, INF));

	for(int i=1; i<=n; i++) {
		cin>>g[0][i];
		g[i][0] = g[0][i];
	}

	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			cin>>g[i][j];
		}
	}
	cout<<prime()<<endl;
}

