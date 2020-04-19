#include<iostream>

using namespace std;

int coins[4] = {64, 16, 4, 1};

int main(void) {
	int n;
	cin>>n;
	n = 1024-n;

	int res = 0;
	for(int i=0; i<4; i++) {
		if(n>=coins[i]){
			res += n/coins[i];
			n = n%coins[i];
			if(n==0) break;
		}
	}
	cout<<res<<endl;
}
