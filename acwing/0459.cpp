#include <iostream>
#include <vector>

using namespace std;

int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

int main(void) {
	int n, x, y;
	cin>>n>>x>>y;
	x--;
	y--;
	vector<vector<int>> f(n, vector<int>(n, 0));

	int val = 0;
	int mode = 0;
	int pos_x = 0;
	int pos_y = 0;
	int cnt = n*n;
	while(val<=cnt) {
		val++;
		f[pos_x][pos_y] = val;
		int nx = pos_x + dx[mode];
		int ny = pos_y + dy[mode];
		if(nx>=0 && ny>=0 && nx<n && ny<n && f[nx][ny]==0){
			pos_x = nx;
			pos_y = ny;
		}else{
			mode = (mode+1)%4;
			pos_x = pos_x + dx[mode];
			pos_y = pos_y + dy[mode];
		}
	}
	cout<<f[x][y]<<endl;
}
