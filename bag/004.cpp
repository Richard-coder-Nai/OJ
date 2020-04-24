#include <iostream>

using namespace std;

int f[1005];

int main(void) {
	int n, m;
	cin>>n>>m;

	for(int i=0; i<n; i++) {
		int v, w, s;
		cin>>v>>w>>s;
		for(int j=m; j>=v; j--) {
			for(int k=0; k<=s && k*v<=j; k++) {
				f[j] = max(f[j], f[j-k*v]+k*w);
			}
		}
	}
	cout<<f[m]<<endl;
}
