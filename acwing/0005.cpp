#include <iostream>

using namespace std;

int N, V;
int f[2005];
int main(void) {
	cin>>N>>V;
	for(int i=0; i<N; i++) {
		int v, w, s;
		cin>>v>>w>>s;
		for(int j=V; j>=v; j--) {
			for(int k=0; k<=s && k*v<=j; k++) {
				f[j] = max(f[j], f[j-k*v]+k*w);
			}
		}
	}
	cout<<f[V]<<endl;
}
