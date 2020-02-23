#include<iostream>
#include<vector>

using namespace std;

vector<vector<char>> g;

int n, m;
int counter;

void dfs(int x, int y){
	counter++;
	g[x][y] = 'x';
	if(x-1>=0 && g[x-1][y]=='.') dfs(x-1, y);
	if(y-1>=0 && g[x][y-1]=='.') dfs(x, y-1);
	if(x+1<n && g[x+1][y]=='.') dfs(x+1, y);
	if(y+1<m && g[x][y+1]=='.') dfs(x, y+1);
}

int main(void){

	while(true){
		cin>>m>>n;
		if(n==0 && m==0) break;
		g.clear();
		g.assign(n, vector<char>(m, '0'));
		int x = 0;
		int y = 0;
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				char tmp;
				cin>>tmp;
				g[i][j] = tmp;
				if(tmp=='@'){
					x = i;
					y = j;
				}
			}
		}
		counter = 0;
		dfs(x, y);
		cout<<counter<<endl;
	}
}
