#include<iostream>
#include<vector>

using namespace std;

vector<vector<char>> g;
int n;

void dfs(int x, int y){
	g[x][y] = 'x';
	if(x-1>=0 && g[x-1][y]=='.') dfs(x-1, y);
	if(y-1>=0 && g[x][y-1]=='.') dfs(x, y-1);
	if(x+1<n && g[x+1][y]=='.') dfs(x+1, y);
	if(y+1<n && g[x][y+1]=='.') dfs(x, y+1);
}

int main(void){
	int k;
	cin>>k;

	for(int i=0; i<k; i++){
		cin>>n;
		g.clear();
		g.assign(n, vector<char>(n, '0'));
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				cin>>g[i][j];
			}
		}
		int x1, y1, x2, y2;
		cin>>x1>>y1>>x2>>y2;
		if(g[x1][y1]=='#' || g[x2][y2]=='#'){
			cout<<"NO"<<endl;
			continue;
		}

		dfs(x1, y1);
		if(g[x2][y2]=='x'){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}
}
