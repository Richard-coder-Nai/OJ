#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

typedef pair<int, int> PII;

static bool cmp(PII p1, PII p2){
	return p1.first<p2.first;
}


vector<PII> table;
int x, y;

int main(void){
	int n;
	cin>>n;

	priority_queue<int, vector<int>, greater<int>> heap;

	for(int i=0; i<n; i++){
		cin>>x>>y;
		table.push_back({x, y});
	}
	sort(table.begin(), table.end(), cmp);



	for(auto it:table){
		if(heap.size()==0 || heap.top()>=it.first){
			heap.push(it.second);
		}else{
			heap.pop();
			heap.push(it.second);
		}
	}

	cout<<heap.size()<<endl;
}
