#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main(void) {
	int n, k;
	cin>>n>>k;

	unordered_map<string, vector<int>> table;

	for(int i=0; i<k; i++) {
		int idx, Nums;
		cin>>idx>>Nums;
		for(int i=0; i<Nums; i++){
			string name;
			cin>>name;
			table[name].push_back(idx);
		}
	}
	for(auto &it:table){
		sort(it.second.begin(), it.second.end());
	}

	for(int i=0; i<n; i++){
		string name;
		cin>>name;
		cout<<name<<" ";
		cout<<table[name].size()<<" ";
		for(int it:table[name]) {
			cout<<it<<" ";
		}
		cout<<endl;
	}
}
