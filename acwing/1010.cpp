#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n;
vector<int> table;

int get_max_num() {
	vector<int> f;

	for(auto it:table) {
		if(f.empty()){
			f.push_back(it);
			continue;
		}
		if(it<table.back()) {
			table.push_back(it);
		}else{
			*lower_bound(table.begin(), table.end(), it) = it;
		}
	}
	return f.size();
}

int main(void) {
	int x;
	while(cin>>x) {
		table.push_back(x);
	}
	n = table.size();

	cout<<get_max_num()<<endl;

	return 0;
}
