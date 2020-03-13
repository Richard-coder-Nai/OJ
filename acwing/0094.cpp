#include<iostream>
#include<vector>

using namespace std;

int n;
vector<int> path;
vector<bool> used;

void dfs(){
	if(path.size()==n){
		for(auto it:path){
			cout<<it<<" ";
		}
		cout<<endl;
	}

	for(int i=1; i<=n; i++){
		if(used[i]==false){
			path.push_back(i);
			used[i] = true;
			dfs();
			used[i] = false;
			path.pop_back();
		}
	}
}

int main(void){
	cin>>n;
	used.assign(n, false);
	dfs();
}
