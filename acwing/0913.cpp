#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(void){
	int n;
	cin>>n;
	
	vector<int> table(n, 0);
	for(int i=0; i<n; i++){
		cin>>table[i];
	}

	sort(table.begin(), table.end());

	for(int i=1; i<n-1; i++){
		table[i] += table[i-1];
	}
	long sum = 0;
	for(int i=0; i<n-1; i++){
		sum += long(table[i]);
	}
	cout<<sum<<endl;
}
