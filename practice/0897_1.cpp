#include <iostream>

using namespace std;

int lena, lenb;
string str_a, str_b;

int f[1005][1005];

int main(void) {
	cin>>lena>>lenb;
	cin>>str_a>>str_b;

	for(int i=1; i<=lena; i++) {
		for(int j=1; j<=lenb; j++) {
			if(str_a[i-1]==str_b[j-1])
				f[i][j] = f[i-1][j-1]+1;
			else {
				f[i][j] = max(f[i-1][j], f[i][j-1]);
			}
		}
	}
	cout<<f[lena][lenb]<<endl;
}
