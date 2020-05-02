#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, w;
int a, b;

vector<pair<int, int>> table;

static bool cmp(pair<int, int> p1, pair<int, int> p2) {
	return p1.second < p2.second;
}

int main(void) {
	cin>>n>>w;
	cin>>a>>b;

	int k = a + b;
	for(int i=0; i<n; i++) {
		int x, y;
		cin>>x>>y;
		table.push_back({x, y});
	}
	sort(table.begin(), table.end(), cmp);


	int res = 0;
	for(int i=0; i<n; i++) {
		if(table[i].first>k) continue;
		if(table[i].second<=w) {
			w-=table[i].second;
			res++;
		}
	}
	cout<<res<<endl;
}
