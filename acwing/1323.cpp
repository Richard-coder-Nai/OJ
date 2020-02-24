#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> table;

int main(void){
	int n;
	cin>>n;
	for(int i=0; i<n; i++){
		int tmp;
		cin>>tmp;
		table.push_back(tmp);
	}

	sort(table.begin(), table.end());

	if(table[0]!=0){
		cout<<0<<endl;
		return 0;
	}

	for(int i=0; i<n-1; i++){
		if(table[i]+1<table[i+1]){
			cout<<table[i]+1<<endl;
			return 0;
		}
	}
	return 0;
}
