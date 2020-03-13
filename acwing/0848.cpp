#include<iostream>
#include<vector>
#include<stack>

using namespace std;

vector<vector<int>> adj;

int main(void){
	int n, m;
	cin>>n>>m;
	adj.assign(n+1, vector<int>());
	vector<int> indegree(n+1, 0);

	for(int i=0; i<m; i++){
		int src, dest;
		cin>>src>>dest;
		adj[src].push_back(dest);
		indegree[dest]++;
	}

	stack<int> stk;
	for(int i=1; i<=n; i++){
		if(indegree[i]==0){
			stk.push(i);
		}
	}

	vector<int> path;
	while(!stk.empty()){
		int top = stk.top();
		path.push_back(top);
		stk.pop();
		indegree[top] = -1;
		for(auto it:adj[top]){
			if(indegree[it>0])
				indegree[it]--;
			if(indegree[it]==0){
				stk.push(it);
			}
		}
	}
	if(path.size()==n){
		for(auto it:path){
			cout<<it<<" ";
		}
		cout<<endl;
	}else{
		cout<<-1<<endl;
	}
}
