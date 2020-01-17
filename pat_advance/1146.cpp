#include<iostream>
#include<vector>
#include<list>

using namespace std;

bool topo_judge(vector<list<int>> adj, vector<int> in_degree){
	vector<int> seq;
	for(int i=0; i<adj.size(); i++){
		int node;
		cin>>node;
		node--;
		seq.push_back(node);
	}
	for(auto it: seq){
		if(in_degree[it]!=0){
			return false;
		}else{
			for(auto j=adj[it].begin(); j!=adj[it].end(); j++){
				in_degree[*j]--;
			}
		}
	}
	return true;
}

int main(void){
	int n,e;
	cin>>n>>e;

	vector<list<int>> adj;
	adj.assign(n, list<int>());
	vector<int> in_degree(n, 0);

	for(int i=0; i<e; i++){
		int src, dest;
		cin>>src>>dest;
		src--;
		dest--;
		in_degree[dest]++;
		adj[src].push_back(dest);
	}

	int test_case;
	cin>>test_case;

	bool first=true;
	for(int i=0; i<test_case; i++){
		if(topo_judge(adj, in_degree)==false){
			if(first==false) cout<<" ";
			cout<<i;
			first=false;
		}
	}
	cout<<endl;
}
