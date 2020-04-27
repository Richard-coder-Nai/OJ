#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e4+3;
struct Node{
	int x, y, w;
};

Node node[10005];
int n, m, k;

void sovler() {
	vector<long long> dist(n+1, INF);
	dist[1] = 0;
	for(int i=0; i<k; i++) {
		vector<long long> back = dist;
		for(int j=0; j<m; j++) {
			auto e = node[j];
			if(back[e.x]!=INF)
				dist[e.y] = min(dist[e.y], back[e.x]+e.w);
		}
	}
	if(dist[n]==INF) cout<<"impossible"<<endl;
	else cout<<dist[n]<<endl;
}

int main(void) {
	cin>>n>>m>>k;
	for(int i=0; i<m; i++) {
		int x, y, w;
		cin>>x>>y>>w;
		node[i] = {x, y, w};
	}
	sovler();
}
