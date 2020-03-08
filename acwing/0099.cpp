#include<iostream>
#include<vector>

using namespace std;

int n, r;
int x, y, v;

int s[5010][5010];

int main(void){
	cin>>n>>r;

	int row = r-1, col = r-1;

	for(int i=0; i<n; i++){
		cin>>x>>y>>v;
		s[x][y] = v;
		row =  max(row, x);
		col =  max(col, y);
	}

	for(int i=1; i<n; i++){
		s[i][0] = s[i-1][0]+s[i][0];
	}
	for(int i=1; i<n; i++){
		s[0][i] = s[0][i-1]+s[0][i];
	}

	for(int i=1; i<=row; i++){
		for(int j=1; j<=col; j++){
			s[i][j] = s[i][j]+s[i-1][j]+s[i][j-1]-s[i-1][j-1];
		}
	}
	int ans = 0;
	for(int i=r; i<=row; i++){
		for(int j=r; j<=col; j++){
			ans = max(s[i][j]-s[i-r][j]-s[i][j-r]+s[i-r][j-r], ans);
		}
	}
	cout<<ans<<endl;
}
