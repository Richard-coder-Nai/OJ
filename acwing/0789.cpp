#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(void){
	int n,q;
	cin>>n>>q;

	vector<int> table(n, 0);
	for(int i=0; i<n; i++){
		cin>>table[i];
	}

	for(int i=0; i<q; i++){
		int k;
		cin>>k;

		auto pos = lower_bound(table.begin(), table.end(), k);
		if(pos!=table.end() && *pos==k){
			cout<<distance(table.begin(), pos);
		}else{
			cout<<"-1 -1"<<endl;
			continue;
		}
		pos = upper_bound(table.begin(), table.end(), k);
		cout<<" ";
		cout<<distance(table.begin(), pos)-1<<endl;
	}
}
