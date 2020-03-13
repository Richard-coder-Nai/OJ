#include<iostream>
#include<map>

using namespace std;

int n, m, target;

int main(void){
	cin>>n>>m>>target;

	map<int, int> table;
	for(int i=0; i<n; i++){
		int tmp;
		cin>>tmp;
		table[target-tmp] = i;
	}

	int counter = 0;
	for(int i=0; i<m; i++){
		int tmp;
		cin>>tmp;
		if(table.count(tmp)){
			cout<<table[tmp]<<" ";
			cout<<i<<endl;
			break;
		} 
	}
	return 0;
}
