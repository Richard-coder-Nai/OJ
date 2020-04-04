#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef pair<int, int> PII;
vector<PII> table;

static bool cmp(PII p1, PII p2){
	return p1.second < p2.second;
}

int n;
int main(void){
	cin>>n;
	for(int i=0; i<n; i++){
		int x, y;
		cin>>x>>y;
		table.push_back({x, y});
	}
	sort(table.begin(), table.end(), cmp);

	int end = -1e9;
	int res = 0;
	for(int i=0; i<n; i++){
		if(end<table[i].first){
			res++;
			end = table[i].second;
		}
	}
	cout<<res<<endl;
}
