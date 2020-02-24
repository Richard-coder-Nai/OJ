#include<iostream>
#include<queue>

using namespace std;

int g[105][105];

int main(void){
	int n, m;
	cin>>n>>m;

	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin>>g[i][j];
		}
	}

	queue<pair<int, int>> q;
	q.push(make_pair(0, 0));
	g[0][0] = 1;

	int step = 0;
	while(!q.empty()){
		int size = q.size();
		for(int i=0; i<size; i++){
			auto front = q.front();
			q.pop();
			int x = front.first;
			int y = front.second;

			if(x+1==n && y+1==m){
				cout<<step<<endl;
				return 0;
			}


			if(x+1<n && g[x+1][y]==0){
				g[x+1][y] = 1;
				q.push(make_pair(x+1, y));
			}
			if(y+1<m && g[x][y+1]==0){
				g[x][y+1] = 1;
				q.push(make_pair(x, y+1));
			}
			if(x-1>=0 && g[x-1][y]==0){
				g[x-1][y] = 1;
				q.push(make_pair(x-1, y));
			}
			if(y-1>=0 && g[x][y-1]==0){
				g[x][y-1] = 1;
				q.push(make_pair(x, y-1));
			}
		}
		step++;
	}
}
