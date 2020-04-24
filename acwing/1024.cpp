#include <iostream>
#include <vector>

using namespace std;

int V, n;
int volume[35];
int f[20005];

int main(void) {
	cin>>V>>n;

	for(int i=1; i<=n; i++) {
		cin>>volume[i];
	}

	for(int i=1; i<=n; i++) {
		for(int j=V; j>=volume[i]; j--) {
			f[j] = max(f[j], f[j-volume[i]]+volume[i]);
		}
	}
	cout<<V-f[V]<<endl;
}
