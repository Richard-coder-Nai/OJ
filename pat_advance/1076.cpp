#include<iostream>
#include<queue>
#include<stack>
#include<list>

using namespace std;


vector<list<int>> adj;



void dfs(int start , int level){

	vector<bool> visited(adj.size(), false);

	visited[start] = true;

	queue<int> q;
	q.push(start);

	int counter = 0;
	int visited_level = 0;

	while(!q.empty()){
		int size = q.size();
		visited_level++;

		for(int i=0; i<size; i++){
			int front = q.front();
			q.pop();
			for(auto it:adj[front]){
				if(visited[it]==false){
					q.push(it);
					visited[it]=true;
					counter++;
				}
			}
		}
		if(level==visited_level){
			break;
		}
	}
	cout<<counter<<endl;
}

int main(void){
	int node_num, level;
	cin>>node_num>>level;

	adj.assign(node_num, list<int>());
	for(int i=0; i<node_num; i++){
		int n;
		cin>>n;
		for(int j=0; j<n; j++){
			int src;
			cin>>src;
			src--;
			adj[src].push_back(i);
		}
	}

	int test_num;
	cin>>test_num;
	vector<int> test_node;
	for(int i=0; i<test_num; i++){
		int t;
		cin>>t;
		t--;

		if(level==0||node_num==0) 
			cout<<0<<endl;
		else{
			dfs(t, level);
		}
	}
}
