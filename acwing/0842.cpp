#include<iostream>
#include<vector>

using namespace std;

int n;
vector<bool> used;
vector<int> path;

void dfs(int p){
	if(p==n) {
		for(auto it:path){
			cout<<it<<" ";
		}
		cout<<endl;
	}

	for(int i=1; i<=n; i++){
		if(used[i]==false){
			used[i] = true;
			path.push_back(i);
			dfs(p+1);
			path.pop_back();
			used[i] = false;
		}
	}
}


int main(void){
	cin>>n;
	used.assign(n+1, false);
	dfs(0);
}
