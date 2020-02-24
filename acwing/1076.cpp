#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int g[105][105];
vector<pair<int, int>> path;
int n;

bool dfs(int x, int y, int step){
	if(x==n-1 && y==n-1){
		path.push_back(make_pair(n-1, n-1));
		return true;
	}

	path.push_back(make_pair(x, y));

	if(x+1<n && g[x+1][y]==step+1){
		if(dfs(x+1, y, step+1))
			return true;
	}
	if(y+1<n && g[x][y+1]==step+1){
		if(dfs(x, y+1, step+1))
			return true;
	}
	if(x-1>=0 && g[x-1][y]==step+1){
		if(dfs(x-1, y, step+1))
			return true;
	}
	if(y-1>=0 && g[x][y-1]==step+1){
		if(dfs(x, y-1, step+1))
			return true;
	}
	path.pop_back();
	return false;
}

int main(void){
	cin>>n;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin>>g[i][j];
			g[i][j] = 0-g[i][j];
		}
	}

	queue<pair<int, int>> q;
	q.push(make_pair(0, 0));

	int step = 1;
	while(!q.empty()){
		int size = q.size();
		for(int i=0; i<size; i++){
			auto front = q.front();
			q.pop();
			int x = front.first;
			int y = front.second;
			g[x][y] = step;
			if(x+1<n && g[x+1][y]==0) q.push(make_pair(x+1, y));
			if(x+1<n && g[x][y+1]==0) q.push(make_pair(x, y+1));
			if(x-1>=0 && g[x-1][y]==0) q.push(make_pair(x-1, y));
			if(y-1>=0 && g[x][y-1]==0) q.push(make_pair(x, y-1));
		}
		step++;
	}
	cout<<endl;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout<<g[i][j]<<" ";
		}
		cout<<endl;
	}

	dfs(0, 0, 1);
	for(auto it:path){
		cout<<it.first<<" "<<it.second<<endl;
	}
}
