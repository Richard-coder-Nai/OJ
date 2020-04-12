#include <iostream>
#include <vector>

using namespace std;

const int N = 1e4+5;
const int INF = 1e7+5;
int n, m, k;

struct Node {
	int x, y, z;
}node[N];


int solver() {
	vector<long long> dist(n+1, INF);
	dist[1] = 0;
	for(int i=0; i<k; i++){
		auto back = dist;
		for(int j=0; j<m; j++){
			auto e = node[j];
			if(back[e.x]!=INF){
				dist[e.y] = min(dist[e.y], back[e.x]+e.z);
			}
		}
	}
	if(dist[n]==INF) {
		cout<<"impossible\n";
	}else{
		cout<<dist[n]<<endl;
	}
}

int main(void) {
	cin>>n>>m>>k;
	for(int i=0; i<m; i++){
		int x, y, z;
		cin>>x>>y>>z;
		node[i].x = x;
		node[i].y = y;
		node[i].z = z;
	}
	solver();
}
