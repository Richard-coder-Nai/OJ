#include<iostream>

int N, V;

int c[1005]; // cost
int w[1005]; // worth
int f[1005];

int main(void) {
	cin>>N>>V;
	for(int i=1; i<=N; i++) cin>>c[i]>>w[i];

	for(int i=1; i<=N; i++) {
		for(int v=c[i]; v<=V; v++) {
			f[v] = max(f[v], f[v-c[i]]+w[i]);
		}
	}

	cout<<f[V]<<endl;
}
