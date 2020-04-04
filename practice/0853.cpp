#include<iostream>
#include<vector>

const int INF = 1e7;

using namespace std;

int n, m, k;

struct Node{
	int x, y, w;
};

Node node[10005];

void bellman_ford(){
	vector<long long> dist(n+1, INF);
	dist[1] = 0;
	for(int i=0; i<k; i++){
		vector<long long> back = dist;
		for(int j=0; j<m; j++){
			auto e = node[j];
			if(back[e.x]!=INF)
				dist[e.y] = min(dist[e.y], back[e.x]+e.w);
		}
	}

	if(dist[n]!=INF)
		cout<<dist[n]<<endl;
	else
		cout<<"impossible"<<endl;
}

int main(void){
	cin>>n>>m>>k;
	for(int i=0; i<m; i++){
		int x, y, z;
		cin>>x>>y>>z;
		node[i] = {x, y, z};
	}
	bellman_ford();
}
