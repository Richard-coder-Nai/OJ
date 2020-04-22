#include <iostream>
#include <map>

using namespace std;

int main(void) {
	int n;
	cin>>n;
	map<int, int> table;
	int res = 0;
	int start = -1;
	for(int i=0; i<n; i++) {
		int x;
		cin>>x;
		if(table.count(x)) {
			start = max(start, table[x]);
		}
		res = max(res, i-start);
		table[x] = i;
	}
	cout<<res<<endl;
}
