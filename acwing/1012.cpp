#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef pair<int, int> PII; 
vector<PII> table;
int n; 

static bool cmp(PII p1, PII p2) {
	return p1.first < p2.first;
}

int main(void) {
	cin>>n;
	for(int i=0; i<n; i++) {
		int x, y;
		cin>>x>>y;
		table.push_back({x, y});
	}
	int res = 1;
	sort(table.begin(), table.end(), cmp);

	vector<int> f(n, 1);

	for(int i=1; i<n; i++) {
		for(int j=0; j<i; j++) {
			if(table[i].second>table[j].second) {
				f[i] = max(f[i], f[j]+1);
				res = max(f[i], res);
			}
		}
	}
	cout<<res<<endl;
}

