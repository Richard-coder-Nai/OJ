#include <iostream>

using namespace std;


int n;
int mod = 10000;


int fib(int n) {
	if(n==0) return 0;
	if(n==1) return 1;
	if(n==2) return 1;

	int a = 1;
	int b = 0;
	int c = a+b;
	for(int i=1; i<n; i++) {
		c = (a+b)%mod;
		b = a;
		a = c;
	}
	return c;
}

int main(void) {
	while(true) {
		cin>>n;
		if(n==-1) break;
		cout<<fib(n)<<endl;
	}
}
