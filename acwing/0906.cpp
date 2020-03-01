#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

vector<bool> used;
vector<pair<int, int>> table;

static bool cmp(pair<int, int> x, pair<int, int> y){
	if(x.first!=y.first) return x.first<y.first;
	else return x.second<y.second;
}

int main(void){
	int n;
	cin>>n;
	used.assign(n, false);

	int size = n;
	while(n--){
		int x, y;
		cin>>x>>y;
		table.push_back(make_pair(x, y));
	}
	sort(table.begin(), table.end(), cmp);

	priority_queue<int, vector<int>, greater<int>> heap;

	for(int i=0; i<size; i++){
		auto cur = table[i];
		if(heap.empty() || heap.top()>=cur.first){
			heap.push(cur.second);
		}else{
			heap.pop();
			heap.push(cur.second);
		}
	}
	cout<<heap.size()<<endl;
}
