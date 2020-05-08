#include <iostream>

using namespace std;

int a, b, k, n, m;
int mod = 10007;

int mypow(int a, int b) {
	if(b==0) return 1;
	if(a==0) return 0;

	int res = 1;
	while(b) {
		if(b&1) res = (res*a)%mod;
		b = b>>1;
		a = (a*a)%mod;
	}

	return res;
}

int main(void) {
	cin>>a>>b>>k>>n>>m;

	int res = mypow(a, n) * mypow(b, n) % mod;

	for (int i = 1, j = k; i <= n; i ++, j -- ) {
		res = res * j % mod;
		res = res * mypow(i, mod - 2) % mod;
	}
	cout<<res<<endl;
}
