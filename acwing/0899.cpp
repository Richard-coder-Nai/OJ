#include<iostream>
#include<vector>
#include<string>
#include<cmath>

using namespace std;

vector<string> s;

int min_editor(string a, string b){
	if(a==b) return 0;
	int lena = a.size();
	int lenb = b.size();
	vector<vector<int>> f(lena+1, vector<int>(lenb+1, 0));
	for(int i=0; i<=lena; i++) f[i][0] = i;
	for(int i=0; i<=lenb; i++) f[0][i] = i;
	for(int i=1; i<=lena; i++){
		for(int j=1; j<=lenb; j++){
			f[i][j] = min(f[i][j-1]+1, f[i-1][j]+1);
			if(a[i-1]==b[j-1]) f[i][j] = min(f[i][j], f[i-1][j-1]);
			else f[i][j] = min(f[i][j], f[i-1][j-1]+1);
		}
	}
	return f[lena][lenb];
}

int main(void){
	int n, k;
	cin>>n>>k;
	for(int i=0; i<n; i++){
		string tmp;
		cin>>tmp;
		s.push_back(tmp);
	}

	while(k--){
		int counter = 0;
		string cmp;
		int c;
		cin>>cmp>>c;
		int size = cmp.size();
		for(int i=0; i<n; i++){
			if(abs(int(size-s[i].size()))>c) continue;
			int dist = min_editor(cmp, s[i]);
			if(dist<=c) counter++;
		}
		cout<<counter<<endl;
	}
}
