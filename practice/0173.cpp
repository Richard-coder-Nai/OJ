#include<iostream>
#include<vector>
#include<string>
#include<queue>

using namespace std;

vector<vector<int>> g;
int n, m;
string str;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main(void){
	cin>>n>>m;
	g.assign(n, vector<int>(m, 0));
	queue<pair<int, int>> q;
	for(int i=0; i<n; i++){
		cin>>str;
		for(int j=0; j<m; j++){
			if(str[j]=='1'){
				q.push({i, j});
				g[i][j] = -1;
			}
		}
	}

	int step = 0;
	while(q.size()){
		int size = q.size();
		step++;
		for(int i=0; i<size; i++){
			auto front = q.front();
			q.pop();
			int x = front.first;
			int y = front.second;
			for(int j=0; j<4; j++){
				int nx = x + dx[j];
				int ny = y + dy[j];
				if(nx>=0 && ny>=0 && nx<n && ny<m && g[nx][ny]==0){
					g[nx][ny] = step;
					q.push({nx, ny});
				}
			}
		}
	}
	for(auto it:g){
		for(auto v:it){
			if(v==-1) cout<<0<<" ";
			else cout<<v<<" ";
		}
		cout<<endl;
	}
}
