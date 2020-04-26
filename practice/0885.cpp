#include <iostream>

using namespace std;

const int N = 2005;
const int mod = 1e9+7;
int n;
int C[N][N];

void init_C(){
	for(int i=0; i<N; i++) {
		C[i][1] = i % mod;
		C[i][0] = 1;
	}
	for(int i=1; i<N; i++) {
		for(int j=1; j<=i; j++) {
			C[i][j] = (C[i-1][j] + C[i-1][j-1]) % mod;
		}
	}
}


int main(void) {
	init_C();
	cin>>n;
	while(n--) {
		int a, b;
		cin>>a>>b;
		cout<<C[a][b]<<endl;
	}
}
