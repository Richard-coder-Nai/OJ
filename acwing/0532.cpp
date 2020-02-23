#include<iostream>
#include<algorithm>

using namespace std;

int main(void){
	int k;
	cin>>k;
	for(int i=0; i<k; i++){
		int n;
		cin>>n;
		vector<int> table(n, 0);
		for(int j=0; j<n; j++){
			cin>>table[j];
		}
		sort(table.begin(), table.end());

		int Max = table[n-1];

		vector<bool> f(Max+1, false);
		f[0] = true;

		int counter = 0;
		for(auto it:table){
			if(f[it]==false) counter++;
			for(int j=it; j<=Max; j++){
				f[j] = f[j-it] || f[j];
			}
		}
		cout<<counter<<endl;
	}
}

