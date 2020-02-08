#include<iostream>

using namespace std;

const int N = 1005;

int v[N];
int w[N];
int f[N];

int main(void){
	int n, m;
	cin>>n>>m;

	for(int i=1; i<=n; i++){
		cin>>v[i]>>w[i];
	}

	for(int i=0; i<=n; i++){
		for(int j=0; j<=m; j++){
			f[j] = max(f[j], f[j-v[i]] + w[i]);
		}
	}
	cout<<f[m];
}
