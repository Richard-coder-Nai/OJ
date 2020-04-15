#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n, m;
vector<vector<int>> g;
vector<int> indegree;
vector<int> path;
vector<int> dist;

int main(void){
	cin>>n>>m;
	g.assign(n+1, vector<int>());
	indegree.assign(n+1, 0);
	dist.assign(n+1, 100);

	for(int i=0; i<m; i++){
		int src, dest;
		cin>>dest>>src;
		g[src].push_back(dest);
		indegree[dest]++;
	}

	queue<int> q;
	for(int i=1; i<=n ;i++){
		if(indegree[i]==0){
			q.push(i);
			path.push_back(i);
			dist[i] = 100;
		}
	}

	while(q.empty()==false){
		int size = q.size();
		for(int i=0; i<size; i++){
			//int front = pq.top();
			int front = q.front();
			q.pop();
			for(auto it:g[front]){
				dist[it] = max(dist[it], dist[front]+1);
				if(indegree[it]>0){
					indegree[it]--;
					if(indegree[it]==0){
						q.push(it);
						path.push_back(it);
					}
				}
			}
		}
	}

	if(path.size()!=n){
		cout<<"Poor Xed"<<endl;
		return 0;
	}
	int res = 0;
	for(int i=1; i<=n; i++){
		res += dist[i];
	}
	cout<<res<<endl;
}
