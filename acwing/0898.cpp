#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int NINF = -10005;

int n;
vector<vector<int>> g;
vector<vector<int>> f;

int main(void){
	cin>>n;
	if(n==1){
		int tmp;
		cin>>tmp;
		cout<<tmp<<endl;
		return 0;
	}
	g.assign(n+1, vector<int>(n+1, NINF));
	f.assign(n+1, vector<int>(n+1, NINF));
	f[0][0] = 0;
	f[0][1] = 0;
	
	int k = 0;
	for(int i=1; i<=n; i++){
		k++;
		for(int j=1; j<=k; j++){
			cin>>g[i][j];
		}
	}

	k = 0;
	for(int i=1; i<=n; i++){
		k++;
		for(int j=1; j<=k; j++){
			f[i][j] = g[i][j] + max(f[i-1][j-1], f[i-1][j]);
		}
	}
	cout<<*max_element(f[n].begin(), f[n].end())<<endl;
}
