#include <iostream>

using namespace std;

const int N = 1e4+5;
int c[N], d[N];
int n, m, w;
int father[N];
int f[N];

int find_fater(int x) {
	int a = x;
	while(x!=father[x]) x = father[x];

	/*
	while(x!=a) {
		int z = father[a];
		father[a] = x;
		a = x;
	}
	*/

	return x;
}

int main(void) {
	cin>>n>>m>>w;
	for(int i=0; i<=n; i++) father[i] = i;

	for(int i=1; i<=n; i++) {
		cin>>c[i]>>d[i];
	}

	for(int i=0; i<m; i++) {
		int x, y;
		cin>>x>>y;

		int fx = find_fater(x);
		int fy = find_fater(y);

		if(fx!=fy) {
			father[fx] = fy;
			c[fy] += c[fx];
			d[fy] += d[fx];
		}
	}

	for(int i=1; i<=n; i++) {
		if(father[i]==i) {
			for(int j=w; j>=c[i]; j--) {
				f[j] = max(f[j], f[j-c[i]]+d[i]);
			}
		}
	}
	cout<<f[w]<<endl;
}
