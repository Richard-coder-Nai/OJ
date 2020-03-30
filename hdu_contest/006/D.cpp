#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

const int INF = 10005;
int n, m;

struct NODE{
	int b, d, p;
};
struct cmp{
    bool operator() (NODE n1, NODE n2) {
		if(n1.d!=n2.d){
			return n1.d > n2.d;
		}
		else{
			return n1.p > n2.p;
		}
	}
};


vector<vector<NODE>> adj;

int a, b, d, p;


void dijstra(int src, int dest){
	vector<int> dist(n+1, INF);
	vector<int> cost(n+1, INF);
	vector<bool> used(n+1, false);

	dist[src] = 0;
	cost[src] = 0;
	priority_queue<NODE, vector<NODE>, cmp> heap;
	heap.push({src, 0, 0});

	while(heap.size()){
		auto top = heap.top();
		heap.pop();

		int Node = top.b;
		int distance = top.d;
		int Cost = top.p;

		if(used[Node]) {
			continue;
		}

		used[Node] = true;
		dist[Node] = distance;
		cost[Node] = Cost;

		for(auto it:adj[Node]){
			if(used[it.b]==false){
				dist[it.b] = min(dist[it.b], distance+it.d);
				int CCC = Cost + it.p;
				//cost[it.b] = min(cost[it.b], Cost+it.p);
				heap.push({it.b, dist[it.b], CCC});
			}
		}
	}
	cout<<dist[dest]<<" "<<cost[dest]<<endl;
}

int main(void){
	while(true){
		scanf("%d%d", &n, &m);
		if(n==m && n==0) break;
		adj.clear();
		adj.assign(n+1, vector<NODE>());

		for(int i=0; i<m; i++){
			scanf("%d%d%d%d", &a, &b, &d, &p);
			adj[a].push_back({b, d, p});
			adj[b].push_back({a, d, p});
		}
		int src, dest;
		scanf("%d%d", &src, &dest);
		dijstra(src, dest);
	}
}
