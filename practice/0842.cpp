#include <iostream>
#include <vector>

using namespace std;


int n;
vector<bool> visited;
vector<int> path;

void dfs() {
	if(path.size()==n){
		for(int v:path){
			cout<<v<<" ";
		}
		cout<<endl;
		return;
	}

	for(int i=1; i<=n; i++) {
		if(visited[i]==false) {
			visited[i] = true;
			path.push_back(i);
			dfs();
			path.pop_back();
			visited[i] = false;
		}
	}
}

int main(void) {
	cin>>n;
	visited.assign(n+1, false);
	dfs();
}
