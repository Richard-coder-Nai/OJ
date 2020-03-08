#include<iostream>
#include<string>

using namespace std;

int lena;
string a;
int lenb;
string b;

int f[1005][1005];

int main(void){
	cin>>lena>>a>>lenb>>b;

	for(int i=0; i<=lena; i++) f[i][0] = i;
	for(int i=0; i<=lenb; i++) f[0][i] = i;

	for(int i=1; i<=lena; i++){
		for(int j=1; j<=lenb; j++){
			f[i][j] = min(f[i][j-1], f[i-1][j]) + 1;
			if(a[i-1]==b[j-1]) f[i][j] = min(f[i-1][j-1], f[i][j]);
			else f[i][j] = min(f[i-1][j-1]+1, f[i][j]);
		}
	}
	cout<<f[lena][lenb]<<endl;
}


