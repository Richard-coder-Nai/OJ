#include<iostream>
#include<unordered_map>

const int mod = 1e9+7;

using namespace std;

int main(void){
	int n, k;
	cin>>n;
	
	unordered_map<int, int> table;

	for(int i=0; i<n; i++){
		cin>>k;
		for(int j=2; j*j<=k; j++){
			if(k%j==0){
				while(k%j==0){
					k /= j;
					table[j]++;
				}
			}
		}
		if(k>1) table[k]++;
	}

	long long res = 1;
	for(auto it:table){
		res = res*(it.second+1)%mod;
	}
	cout<<res<<endl;
}
