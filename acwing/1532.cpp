#include<iostream>
#include<algorithm>
#include<set>

using namespace std;


int main(void) {
	int n, m;
	cin>>n>>m;
	set<int> table;

	pair<int, int> res{10000, 10000};

	for(int i=0; i<n; i++){
		int x;
		cin>>x;
		if(table.count(m-x)){
			int first = min(x, m-x);
			int second = max(x, m-x);
			if(first<res.first){
				res = {first, second};
			}
		}else{
			table.insert(x);
		}
	}
	if(res.first!=10000){
		cout<<res.first<<" "<<res.second<<endl;
	}
	else{
		cout<<"No Solution"<<endl;
	}
}
