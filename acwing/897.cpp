#include<iostream>
#include<string>

using namespace std;

string s1, s2;
int n, m;
int f[1005][1005];


int main(void){
	cin>>n;
	cin>>m;
	cin>>s1;
	cin>>s2;

	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			f[i][j] = max(f[i-1][j], f[i][j-1]);
			if(s1[i-1]==s2[j-1]){
				f[i][j] = f[i-1][j-1]+1;
			}
		}
	}
	cout<<f[n][m]<<endl;
}
