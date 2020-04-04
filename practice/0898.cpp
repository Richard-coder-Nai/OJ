#include<iostream>
#include<vector>

const int NINF = -10005;

using namespace std;

int f[1005][1005];
int g[1005][1005];

int n;
int main(void){
	cin>>n;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=i; j++){
			cin>>g[i][j];
		}
	}
	for(int i=n; i>=1; i--){
		for(int j=i; j>=1; j--){
			f[i][j] += max(f[i+1][j+1], f[i+1][j])+g[i][j];
		}
	}
	cout<<f[1][1]<<endl;
}
