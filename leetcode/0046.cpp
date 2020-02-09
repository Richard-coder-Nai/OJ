#include<iostream>
#include<vector>
#include<set>

using namespace std;

vector<int> nums = {1, 2 ,3};
vector<int> path;
vector<bool> visited;

set<vector<int>> table;

void dfs(){
	if(path.size()==nums.size()){
		for(int i=0; i<path.size(); i++){
			cout<<path[i]<<" ";
		}
		cout<<endl;
		table.insert(path);
		return;
	}
	for(int i=0; i<nums.size(); i++){
		if(!visited[i]){
			path.push_back(nums[i]);
			visited[i] = true;
			dfs();
			visited[i] = false;
			path.pop_back();
		}
	}
}


int main(void){
	visited.assign(nums.size(), false);
	dfs();
}
