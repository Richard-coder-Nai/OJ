#include <iostream>

using namespace std;

int f[1005];

int main(void) {
	int n, m;
	cin>>n>>m;
	for(int i=0; i<n; i++) {
		int v, w;
		cin>>v>>w;
		for(int j=v; j<=m; j++) {
			f[j] = max(f[j], f[j-v]+w);
		}
	}
	cout<<f[m]<<endl;
}
