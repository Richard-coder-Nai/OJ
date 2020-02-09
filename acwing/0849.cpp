#include<iostream>
#include<vector>
#include<cstring>

#define MAX 10001

using namespace std;

int graph[505][505];
int dist[505];
bool visited[505];

int n, m;

int dijskra(){
	dist[1] = 0;

	for(int i=0; i<n; i++){
		int t = -1, cmp = MAX;

		for(int j=1; j<=n; j++){
			if(visited[j]==false && dist[j]<cmp){
				cmp = dist[j];
				t = j;
			}
		}
		if(t==-1) return -1;
		visited[t] = true;

		for(int j=1; j<=n; j++){
			if(graph[t][j]!=MAX)
				dist[j] = min(dist[j], dist[t]+graph[t][j]);
		}
	}
	return dist[n];
}


int main(void){
	cin>>n>>m;
	
	memset(graph, MAX, sizeof(graph));
	memset(dist, MAX, sizeof(dist));
	memset(visited, false, sizeof(visited));


	for(int i=0; i<m; i++){
		int x,y,z;
		cin>>x>>y>>z;
		graph[x][y] = min(z, graph[x][y]);
	}

	cout<<dijskra()<<endl;
}
