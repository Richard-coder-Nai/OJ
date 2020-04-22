#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int a, b;

int min_editor_dist(string str_a, string str_b) {
	int a = str_a.size();
	int b = str_b.size();
	vector<vector<int>> f(a+1, vector<int>(b+1, 0));
	for(int i=0; i<=a; i++) {
		f[i][0] = i;
	}
	for(int i=0; i<=b; i++) {
		f[0][i] = i;
	}
	for(int i=1; i<=a; i++) {
		for(int j=1; j<=b; j++) {
			f[i][j] = min(f[i-1][j]+1, f[i][j-1]+1);
			if(str_a[i-1]==str_b[j-1]) {
				f[i][j] = min(f[i-1][j-1], f[i][j]);
			}else{
				f[i][j] = min(f[i-1][j-1]+1, f[i][j]);
			}
		}
	}
	return f[a][b];
}


int main(void) {
	vector<string> table;
	int n, m;
	cin>>n>>m;
	for(int i=0; i<n; i++) {
		string str;
		cin>>str;
		table.push_back(str);
	}

	for(int i=0; i<m; i++){
		string str;
		int cmp;
		cin>>str>>cmp;
		int cnt = 0;
		for(auto it:table) {
			if(abs(int(it.size())-int(str.size()))>cmp) continue;
			if(min_editor_dist(str, it)<=cmp){
				cnt++;
			}
		}
		cout<<cnt<<endl;
	}
}	
