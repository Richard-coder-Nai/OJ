#include<iostream>
#include<string>

int g[105][105];
int ans[105][105];

using namespace std;

int k, n, m;

int main(void){
	cin>>k;

	while(k--){
		cin>>n>>m;
		for(int i=0; i<n; i++){
			string tmp;
			cin>>tmp;
			for(int j=0; j<m; j++){
				g[i][j] = tmp[j]-'0';
			}
		}

	}
}


