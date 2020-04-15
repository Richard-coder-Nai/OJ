#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int n;

vector<vector<int>> adj;

vector<int> path;
vector<int> indegree;
stack<int> stk;

int main(void) {
	cin>>n;
	adj.assign(n+1, vector<int>());
	indegree.assign(n+1, 0);

	// input
	for(int i=1; i<=n; i++){
		while(true){
			int x;
			cin>>x;
			if(x==0) break;
			adj[i].push_back(x);
			indegree[x]++;
		}
	}
	for(int i=1; i<=n; i++){
		if(indegree[i]==0){
			stk.push(i);
			path.push_back(i);
		}
	}

	while(stk.size()){
		int top = stk.top();
		stk.pop();
		for(auto it:adj[top]){
			if(indegree[it]>0){
				indegree[it]--;
				if(indegree[it]==0){
					stk.push(it);
					path.push_back(it);
				}
			}
		}
	}

	for(auto it:path){
		cout<<it<<" ";
	}
	cout<<endl;
}
