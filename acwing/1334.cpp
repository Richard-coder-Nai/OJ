#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n, m;

// map
// 1 : boom
// 0 : no boom

// state
// 0 : no flag and no detected
// 1 : flagged
// 2 : detected

ector<vector<int, int>> g;

int main(void) {
	cin>>n>>m;

	g.assign(n+1, vector<int>(m+1, {0, 0}));

	// no boom nums
	int cnt = n*n;

	for(int i=1; i<=n; i++) {
		string str;
		cin>>str;
		for(int j=1; j<=m; j++) {
			if(str[j-1]=='*') {
				g[i][j] = {1, 0};
				cnt--;
			}
		}
	}

	bool isWin = false;

	// state
	// 0 : no flag and no detected
	// 1 : flagged
	// 2 : detected
	while(true) {
		string opt;
		int x, y;

		cin>>opt;
		if(opt=="Quit") {
			return 0;
		}

		cin>>x>>y;
		if(opt=="Flag") {
			if(g[x][y].second==2) cout<<"swept"<<endl;
			if(g[x][y].second==1) {
				cout<<"cancelled"<<endl;
				g[x][y].second = 0;
			}
			if(g[x][y].second==0) {
				cout<<"success"<<endl;
				g[x][y].second = 1;
			}
		}

		if(opt=="Sweep") {
			if(g[x][y].second==2) cout<<"swept"<<endl;
			if(g[x][y].second==1) cout<<"flagged"<<endl;
			if(g[x][y]==0) {
				// TODO
			}
		}

		if(opt=="DSweep") {
			if(g[x][y].second==0) cout<<"no swept"<<endl;

		}
	}
}

