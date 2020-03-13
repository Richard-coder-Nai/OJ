#include<iostream>
#include<vector>

using namespace std;

int n, m;

vector<bool> used;
vector<int> path;

void dfs(int p){
	if(path.size()==m){
		for(auto it:path) cout<<it<<" ";
		cout<<endl;
		return;
	}
	for(int i=p; i<=n; i++){
		if(used[i]==false){
			used[i] = true;
			path.push_back(i);
			dfs(i+1);
			path.pop_back();
			used[i] = false;
		}
	}
}


int main(void){
	cin>>n>>m;
	used.assign(n, false);
	dfs(1);
}
