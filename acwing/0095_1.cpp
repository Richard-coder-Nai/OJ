#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<vector<bool>> table(5, vector<bool>(5, false));
vector<vector<bool>> g;

int dx[5] = {1, -1, 0, 0, 0};
int dy[5] = {0, 0, 1, -1, 0};

void turn(int x, int y) {
	for(int i=0; i<5; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(nx>=0 && ny>=0 && nx<5 && ny<5){
			g[nx][ny] = !g[nx][ny];
		}
	}
}

void solve() {
	string str;
	for(int i=0; i<5; i++) {
		cin>>str;
		for(int j=0; j<5; j++) {
			table[i][j] = bool(str[j]-'0');
		}
	}

	int res = 10;
	for(int opt=0; opt<32; opt++) {
		int cnt = 0;
		g = table;

		// first line
		for(int i=0; i<5; i++) {
			if(opt>>i&1) {
				turn(0, i);
				cnt++;
			}
		}

		// 1-4
		for(int i=0; i<4; i++) {
			for(int j=0; j<5; j++) {
				if(g[i][j]==false) {
					turn(i+1, j);
					cnt++;
				}
			}
		}

		// check
		bool sucess = true;
		for(int i=0; i<5; i++) {
			if(g[4][i]==false) sucess = false;
		}

		if(sucess) {
			res = min(res, cnt);
		}
	}
	if(res>6) cout<<"-1"<<endl;
	else cout<<res<<endl;
}

int main(void) {
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}
