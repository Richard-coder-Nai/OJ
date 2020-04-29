#include <iostream>

using namespace std;

int main(void) {
	long long a;
	int b, p;
	cin>>a>>b>>p;

	if(p==1) {
		cout<<0<<endl;
		return 0;
	}

	int res = 1;
	while(b) {
		if(b&1) {
			res = res*a%p;
		}
		b = b>>1;
		a = a*a%p;
	}
	cout<<res<<endl;
}
