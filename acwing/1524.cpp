#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

string str;

int main(void){
	getline(cin, str);

	int n = str.size();
	string re_str = str;
	reverse(re_str.begin(), re_str.end());
	if(str==re_str){
		cout<<n<<endl;
		return 0;
	}

	vector<vector<int>> f(n, vector<int>(n, 0));

	int res = 1;

	for(int i=0; i<n; i++) f[i][i] = 1;

	for(int i=1; i<n; i++) {
		if(str[i]==str[i-1]){
			f[i-1][i] = 1;
			res = 2;
		}
	}

	for(int l=3; l<=n; l++){
		for(int i=0; i+l-1<n; i++){
			int end = i+l-1;
			if(str[i]==str[end] && f[i+1][end-1]==1){
				f[i][end] = 1;
				res = max(l, res);
			}
		}
	}
	cout<<res<<endl;
}
