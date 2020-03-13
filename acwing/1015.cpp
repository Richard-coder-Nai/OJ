#include<iostream>
#include<vector>

using namespace std;

int main(void){
	int N;
	cin>>N;

	for(int i=0; i<N; i++){
		int n, m;
		cin>>n>>m;

		vector<vector<int>> g(n+1, vector<int>(m+1, 0));
		for(int i=1; i<=n; i++){
			for(int j=1; j<=m; j++){
				cin>>g[i][j];
			}
		}

		vector<vector<int>> f(n+1, vector<int>(m+1, 0));
		for(int i=1; i<=n; i++){
			for(int j=1; j<=m; j++){
				f[i][j] = g[i][j]+max(f[i-1][j], f[i][j-1]);
			}
		}
		cout<<f[n][m]<<endl;
	}
}
