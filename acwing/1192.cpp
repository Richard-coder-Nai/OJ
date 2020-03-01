#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n, m;
vector<vector<int>> g;
vector<int> indegree;
vector<int> path;

int main(void){
	cin>>n>>m;
	g.assign(n+1, vector<int>());
	indegree.assign(n+1, 0);

	for(int i=0; i<m; i++){
		int src, dest;
		cin>>dest>>src;
		g[src].push_back(dest);
		indegree[dest]++;
	}

	//priority_queue<int, vector<int>, less<int>> pq;
	queue<int> q;
	for(int i=1; i<=n ;i++){
		if(indegree[i]==0){
			//pq.push(i);
			q.push(i);
			path.push_back(i);
		}
	}

	int res = 0;
	int degree = 100;
	while(q.empty()==false){
		int size = q.size();
		res += (degree*size);
		for(int i=0; i<size; i++){
			//int front = pq.top();
			int front = q.front();
			q.pop();
			for(auto it:g[front]){
				if(indegree[it]>0){
					indegree[it]--;
					if(indegree[it]==0){
						q.push(it);
						path.push_back(it);
					}
				}
			}
		}
		degree++;
	}

	if(path.size()!=n){
		cout<<"Poor Xed"<<endl;
		return 0;
	}
	cout<<res<<endl;
}
