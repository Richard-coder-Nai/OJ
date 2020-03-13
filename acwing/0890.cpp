#include<iostream>
#include<vector>
#include<bitset>

using namespace std;

const int N = 1e9+1;
bitset<N> isdived(0);

int main(void){
	int n, m;
	cin>>n>>m;
	vector<int> p(m, 0);

	for(int i=0; i<m; i++){
		cin>>p[i];
	}


	for(auto it:p){
		for(int i=1; i*it<=n; i++){
			isdived[i*it] = 1;
		}
	}

	cout<<isdived.count()<<endl;
	
}
