#include <iostream>
#include <unordered_map>

using namespace std;

const int mod = 1e9+7;

int main(void) {
	int k;
	cin>>k;
	unordered_map<int, int> table;

	while(k--) {
		int x;
		cin>>x;
		for(int i=2; i<=x/i; i++) {
			while(x%i==0) {
				x = x/i;
				table[i]++;
			}
		}
		if(x>1) {
			table[x]++;
		}
	}

	long long res = 1;
	for(auto prime:table){           
		int p = prime.first;
		int a = prime.second;
		long long t = 1;
		while(a--) {
			t = (t*p+1)%mod;
		}
		res = res*t%mod;
	}
	cout<<res<<endl;

}

