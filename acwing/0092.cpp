#include<iostream>
#include<vector>

using namespace std;

int n;

vector<int> path;
vector<bool> used;

void dfs(int p){
	for(auto it:path) cout<<it<<" ";
	cout<<endl;

	for(int i=p; i<=n; i++){
		if(used[i]==false){
			path.push_back(i);
			used[i] = true;
			dfs(i+1);
			used[i] = false;
			path.pop_back();
		}
	}
}

int main(void){
	cin>>n;
	used.assign(n+1, false);
	dfs(1);
}
