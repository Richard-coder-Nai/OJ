#include <iostream>
#include <unordered_map>

using namespace std;

int n;

int main(void) {
	scanf("%d", &n);
	int res = 1;
	int start = 0;
	unordered_map<int, int> table;
	for(int i=1; i<=n; i++) {
		int x;
		scanf("%d", &x);
		if(table.count(x) && table[x]>=start) {
			start = table[x];
		}
		res = max(res, i-start);
		table[x] = i;
	}
	cout<<res<<endl;
}
