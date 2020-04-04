#include<iostream>
#include<vector>

using namespace std;

const int INF = 200005;

int n, m, k;
struct Node{
	int x, y, w;
};

vector<long long> dist;

Node node[10005];

void solution(){
	dist[1] = 0;
	for(int i=0; i<k; i++){
		vector<long long> last = dist;
		for(int j=0; j<m; j++){
			int x = node[j].x;
			int y = node[j].y;
			int w = node[j].w;
			if(last[x]!=INF)
				dist[y] = min(dist[y], last[x]+w);
		}
	}
	if(dist[n]!=INF)
		cout<<dist[n]<<endl;
	else{
		cout<<"impossible"<<endl;
	}
}

int main(void){
	cin>>n>>m>>k;
	dist.assign(n+1, INF);
	for(int i=0; i<m; i++){
		int a, b, c;
		cin>>a>>b>>c;
		node[i] = {a, b, c};
	}
	solution();
}

