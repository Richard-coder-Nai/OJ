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
int x, y;
int main(void){
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>x>>y;
		table.push_back({x, y});
	}
	sort(table.begin(), table.end(), cmp);

	int end = table[0].second;
	int res = 1;
	for(int i=1; i<n; i++){
		if(end<table[i].first){
			res++;
			end = table[i].second;
		}
	}
	cout<<res<<endl;
}
