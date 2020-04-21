#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

int n;
vector<int> nums;
vector<int> path;
vector<vector<int>> res;
set<vector<int>> table;
vector<bool> used;

void dfs(){
	if(path.size()==n){
		res.push_back(path);
		return;
	}
	for(int i=0; i<n; i++){
		if(i>0 && nums[i]==nums[i-1] && used[i-1]==true){
			continue;
		}
		if(used[i]==false) {
			path.push_back(nums[i]);
			used[i] = true;
			dfs();
			used[i] = false;
			path.pop_back();
		}
	}
}

int main(void) {
	cin>>n;
	nums.assign(n, 0);
	used.assign(n, false);

	for(int i=0; i<n; i++) {
		cin>>nums[i];
	}
	sort(nums.begin(), nums.end());
	dfs();

	for(auto it:res){
		for(int v:it){
			cout<<v<<" ";
		}
		cout<<endl;
	}
}

