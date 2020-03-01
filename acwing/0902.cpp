#include<iostream>
#include<string>

using namespace std;

int lena;
int lenb;
string a;
string b;

int f[1005][1005];

int main(void){
	cin>>lena>>a;
	cin>>lenb>>b;
	for(int i=0; i<=lena; i++) f[i][0] = i;
	for(int i=0; i<=lenb; i++) f[0][i] = i;
	for(int i=1; i<=lena; i++){
		for(int j=1; j<=lenb; j++){
			f[i][j] = min(f[i-1][j]+1, f[i][j-1]+1);
			if(a[i]==b[j]) f[i][j] = min(f[i-1][j-1], f[i][j]);
			else f[i][j] = min(f[i][j], f[i-1][j-1]+1);
		}
	}
	cout<<f[lena][lenb]<<endl;
}
