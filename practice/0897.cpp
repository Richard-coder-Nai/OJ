#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(void){
	int n, m;
	string str1, str2;

	cin>>n>>m;
	cin>>str1>>str2;

	vector<vector<int>> f(n+1, vector<int>(m+1, 0));
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			f[i][j] = max(f[i-1][j], f[i][j-1]);
			if(str1[i-1]==str2[j-1]) f[i][j] = f[i-1][j-1]+1;
		}
	}
	cout<<f[n][m]<<endl;
}
