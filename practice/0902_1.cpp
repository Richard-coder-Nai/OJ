#include<iostream>
#include<string>

using namespace std;

int lena, lenb;
string str_a, str_b;

int f[1005][1005];

int main(void){
	cin>>lena>>str_a;
	cin>>lenb>>str_b;

	for(int i=0; i<=lena; i++) f[i][0] = i;
	for(int i=0; i<=lenb; i++) f[0][i] = i;

	/*
	for(int i=0; i<=lena; i++){
		for(int j=0; j<=lenb; j++){
			cout<<f[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	*/


	for(int i=1; i<=lena; i++){
		for(int j=1; j<=lenb; j++){
			f[i][j] = min(f[i-1][j]+1, f[i][j-1]+1);
			if(str_a[i-1]==str_b[j-1]){
				f[i][j] = min(f[i-1][j-1], f[i][j]);
			}else{
				f[i][j] = min(f[i-1][j-1]+1, f[i][j]);
			}
		}
	}
	/*
	for(int i=0; i<=lena; i++){
		for(int j=0; j<=lenb; j++){
			cout<<f[i][j]<<" ";
		}
		cout<<endl;
	}
	*/
	cout<<f[lena][lenb]<<endl;
}
