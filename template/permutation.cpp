#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin>>n;
	vector<int> table;

	for(int i=1; i<=n; i++) {
		table.push_back(i);
	}

	do{
		for(int it:table) cout<<it<<" ";
		cout<<endl;
	}while(next_permutation(table.begin(), table.end()));
}
