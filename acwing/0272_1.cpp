#include <iostream>

using namespace std;

const int N = 3010;
int n;
int num1[N], num2[N];
int f[3010][3010];

int main(void) {
	cin>>n;
	for(int i=1; i<=n; i++) cin>>num1[i];
	for(int i=1; i<=n; i++) cin>>num2[i];

	for(int i=1; i<=n; i++) {
		int cnt = 1;
		for(int j=1; j<=n; j++) {
			f[i][j] = f[i-1][j];
			if(num1[i]==num2[j]) {
				f[i][j] = max(f[i][j], cnt);
			}
			if(num1[i]>num2[j]) {
				cnt = max(cnt, f[i-1][j]+1);
			}
		}
	}

	int res = 0;
	for(int i=1; i<=n; i++) res = max(res, f[n][i]);
	cout<<res<<endl;
}
