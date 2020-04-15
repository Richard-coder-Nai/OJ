#include<iostream>

using namespace std;

int n;
int main(void) {
	cin>>n;
	while(n--){
		int b;
		long long a, p;
		cin>>a>>b>>p;

		long long res = 1;
		while(b) {
			if(b&1) res = res*a%p;
			b = b>>1;
			a = a*a%p;
		}
		cout<<res<<endl;
	}
}
