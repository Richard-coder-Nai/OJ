#include<iostream>
#include<vector>

using namespace std;

/*
vector<vector<int>> grid = {{1,1,0,0,0},
						   {1,1,0,0,0},
						   {0,0,0,1,1},
						   {0,0,0,1,1}};
						   */
vector<vector<int>> grid = {{0}};

vector<vector<pair<int, int>>> father;
vector<vector<int>> counter;

void init(int n, int m){
	father.resize(n);
	counter.resize(n);

	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			father[i].push_back(make_pair(i, j));
			counter[i].push_back(0);
		}
	}
}

pair<int, int> find_father(pair<int, int> pos){
	auto a = pos;
	while(pos!=father[pos.first][pos.second]){
		pos = father[pos.first][pos.second];
	}
	while(a!=pos){
		auto z = father[a.first][a.second];
		father[a.first][a.second] = pos;
		a = z;
	}
	return pos;
}

void Union(pair<int,int> x, pair<int, int> y){
	auto fx = find_father(x);
	auto fy = find_father(y);
	if(fx!=fy){
		father[fx.first][fx.second] = fy;
	}
}

int main(void){
	int n = grid.size();
	int m = grid[0].size();
	init(n, m);

	for(int i=1; i<m; i++){
		if(grid[0][i]==1 && grid[0][i-1]==1){
			Union(make_pair(0, i), make_pair(0, i-1));
		}
	}
	for(int i=1; i<n; i++){
		if(grid[i][0]==1 && grid[i-1][0]==1){
			Union(make_pair(i, 0), make_pair(i-1, 0));
		}
	}


	for(int i=1; i<n; i++){
		for(int j=1; j<m; j++){
			if(grid[i][j]==1){
				if(grid[i-1][j]==1){
					Union(make_pair(i, j), make_pair(i-1, j));
				}
				if(grid[i][j-1]==1){
					Union(make_pair(i, j), make_pair(i, j-1));
				}
			}
		}
	}

	int max = 0;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(grid[i][j]==1){
				auto f = find_father(make_pair(i, j));
				counter[f.first][f.second] += 1;
				if(counter[f.first][f.second]>max) max = counter[f.first][f.second];

			}
		}
	}
	cout<<max<<endl;
}
