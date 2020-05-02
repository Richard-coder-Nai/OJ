#include <iostream>

using namespace std;

int n;
int num1[3005], num2[3005];
int f[3005][3005];

int main(void) {
	cin>>n;

	for(int i=1; i<=n; i++) cin>>num1[i];
	for(int i=1; i<=n; i++) cin>>num2[i];

	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			f[i][j] = f[i-1][j];
			if(num1[i]==num2[j]) {
				int cnt = 1;
				for(int k=1; k<j; k++) {
					if(num2[k]<num2[j]) cnt = max(cnt, f[i-1][k]+1);
				}
				f[i][j] = max(f[i][j], cnt);
			}
		}
	}


	int res = 0;
	for(int i=0; i<=n; i++) res = max(res, f[n][i]);
	cout<<res<<endl;
}
