#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef pair<int, int> PII;
vector<PII> table;

static bool cmp(PII p1, PII p2){
	if(p1.second != p2.second){
		return p1.second<p2.second;
	}else{
		return p1.first<p2.first;
	}
}

int main(void){
	int n;
	cin>>n;
	for(int i=0; i<n; i++){
		int x, y;
		cin>>x>>y;
		table.push_back({x, y});
	}
	sort(table.begin(), table.end(), cmp);


	int end = table[0].second;
	int res = 1;
	for(int i=1; i<n; i++){
		if(table[i].first>end){
			end = table[i].second;
			res++;
		}
	}
	cout<<res<<endl;
}
