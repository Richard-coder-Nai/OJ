#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void) {
	int n;
	cin>>n;
	vector<int> table;
	for(int i=0; i<n; i++){
		int x;
		cin>>x;
		if(table.empty()){
			table.push_back(x);
			continue;
		}
		if(table.back()<x) {
			table.push_back(x);
		}
		else {
			*lower_bound(table.begin(), table.end(), x) = x;
		}
	}
	cout<<table.size()<<endl;
}
