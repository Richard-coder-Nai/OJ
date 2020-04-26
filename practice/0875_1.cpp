#include <iostream>

using namespace std;

void solver() {
	long long a;
	int b, p;
	cin>>a>>b>>p;

	int res = 1;
	while(b) {
		if(b&1) {
			res = (res*a)%p;
		}
		b = b>>1;
		a = (a*a)%p;
	}
	cout<<res<<endl;
}

int main(void) {
	int n;
	cin>>n;
	while(n--) {
		solver();
	}
}
