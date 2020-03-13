#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<pair<int, int>> table;

static bool cmp(pair<int, int> x, pair<int, int> y){
	if(x.second!=y.second)
		return x.second < y.second;
	else
		return x.first < y.first;
	
}

int main(void){
	int n;
	cin>>n;
	while(n--){
		int x, y;
		cin>>x>>y;
		table.push_back(make_pair(x, y));
	}
	sort(table.begin(), table.end(), cmp);

	int end = table[0].second;
	int res = table.size();

	for(int i=1; i<table.size(); i++){
		if(end>=table[i].first){
			res --;
		}

		else{
			end = table[i].second;
		}
	}
	cout<<res<<endl;
}
