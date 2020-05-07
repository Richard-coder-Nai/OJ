#include <iostream>
#include <string>

using namespace std;

int n, k;

bool used[10] = {false};

string str;

long long res = 0;


void dfs(int idx, int cnt, long long cur) {
	if(cnt==k) {
		res = max(cur, res);
		cout<<res<<endl;
	}
	
	for(int i=1; i<n; i++) {
		if(used[i]==false) {
			used[i] = true;
			cur = cur*atoi(str.substr(idx, i-idx).c_str());
			cout<<cur<<endl;
			dfs(i, cnt+1, cur);
			used[i] = false;
		}
	}
}

int main(void) {
	cin>>n>>k;

	cin>>str;
	dfs(0, 0, 1);
	cout<<res<<endl;
}
