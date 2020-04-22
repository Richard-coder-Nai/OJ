#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<pair<int, int>> table;

static bool cmp(pair<int, int> p1, pair<int, int> p2) {
	if(p1.first==p2.first) {
		p1.second < p2.second;
	}
	return p1.first < p2.first;
}

int main(void) {
	cin>>n;
	for(int i=0; i<n; i++) {
		int x, y;
		cin>>x>>y;
		table.push_back({x, y});
	}
	sort(table.begin(), table.end(), cmp);

	int start = table[0].first;
	int end = table[0].second;
	int res = n;

	for(int i=1; i<n; i++) {
		if(table[i].first > end) {
			start = table[i].first;
			end = max(table[i].second, end);
		}
		else{
			end = table[i].second;
			res--;
		}
	}
	cout<<res<<endl;
}
