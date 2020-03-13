#include<iostream>
#include<map>

using namespace std;

int main(void){
	int k;
	cin>>k;

	while(k--){
		map<int, int> table;
		int n; 
		cin>>n;
		while(n--){
			int x;
			cin>>x;
			table[x]++;
		}
		int mx = n;
		int res = -1;
		for(auto it:table){
			if(it.second>mx){
				mx = it.second;
				res = it.first;
			}
		}
		cout<<res<<endl;
	}
}
