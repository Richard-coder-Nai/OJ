#include <iostream>
#include <vector>

using namespace std;

const int N = 1e5+3;
int a[N], b[N];

int main(void) {
	int n, m, x;
	cin>>n>>m>>x;

	for(int i=0; i<n; i++) cin>>a[i];
	for(int i=0; i<m; i++) cin>>b[i];

	for(int i=0; i<n; i++) {
		int j = m-1;
		while(j>=0 && a[i]+b[j]>=x) {
			if(a[i]+b[j]==x){
				cout<<i<<" "<<j<<endl;
				return 0;
			}
			j--;
		}
	}
	
	return 0;
}
