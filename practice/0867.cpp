#include <iostream>

using namespace std;

void divide(int x) {
	for(int i=2; i<=x/i; i++) {
		if(x%i==0) {
			int cnt = 0;
			while(x%i==0) {
				cnt++;
				x = x/i;
			}
			cout<<i<<" "<<cnt<<endl;
		}
	}
	if(x>1) {
		cout<<x<<" "<<1<<endl;
	}
	cout<<endl;
}

int main(void) {
	int t;
	cin>>t;
	while(t--) {
		int x;
		cin>>x;
		divide(x);
	}
}
