#include<iostream>
#include<map>

using namespace std;

int x;
map<int, int> table;

int main(void){
	int n;
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>x;
		table[x]++;
	}

	int mx = 0;
	int res = -1;
	for(auto it=table.rbegin(); it!=table.rend(); it++){
		if((*it).second>mx){
			mx = (*it).second;
			res= (*it).first;
		}
	}
	cout<<res<<endl;
}
