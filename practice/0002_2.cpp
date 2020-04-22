#include<iostream>

using namespace std;

int N, V;
int c[1005]; //cost
int w[1005]; //worth
int f[1005];

int main(void) {
	cin>>N>>V;
	for(int i=1; i<=N; i++){
		cin>>c[i]>>w[i];
	}
	for(int i=1; i<=N; i++){ // i idx
		for(int v=V; v>=c[i]; v--){ // v volume
			f[v] = max(f[v], f[v-c[i]]+w[i]);
		}
	}
	cout<<f[V]<<endl;
}

for(int i=1; i<=N; i++){ // i idx
	for(int v=V; v>=c[i]; v--){ // v volume
		f[v] = max(f[v], f[v-c[i]]+w[i]);
	}
}

