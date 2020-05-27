#include<iostream>
#include<vector>
#include<queue>


using namespace std;

int n, m;
vector<vector<int>> g;

int bfs(vector<vector<int>> g, int a, int b){
	if(g[a][b]==1){
		return 0;
	}

	queue<pair<int, int>> q;
	q.push(make_pair(a, b));
	g[a][b] = -1;
	int step = 0;
	/*
	while(!q.empty()){
		int size = q.size();
		for(int i=0; i<size; i++){
			auto front = q.front();
			q.pop();
			int x = front.first;
			int y = front.second;
			g[x][y] = -1;
			if(x+1<n){
				if(g[x+1][y]==0){
					q.push(make_pair(x+1, y));
				}
				if(g[x+1][y]==1){
					return step+1;
				}
			}
			if(y+1<n){
				if(g[x][y+1]==0){
					q.push(make_pair(x, y+1));
				}
				if(g[x][y+1]==1){
					return step+1;
				}
			}
			if(y-1>=0){
				if(g[x][y-1]==0){
					q.push(make_pair(x, y-1));
				}
				if(g[x][y-1]==1){
					return step+1;
				}
			}
			if(x-1>=0){
				if(g[x-1][y]==0){
					q.push(make_pair(x-1, y));
				}
				if(g[x-1][y]==1){
					return step+1;
				}
			}


		}
		step++;
	}
	*/ return -1; } int main(void){ cin>>n>>m; g.assign(n, vector<int>(m, 0)); for(int i=0; i<n; i++){ for(int j=0; j<m; j++){ cin>>g[i][j]; } } for(int i=0; i<n; i++){ for(int j=0; j<m; j++){
			cout<<bfs(g, i, j);
		}
	}

}
