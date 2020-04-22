#include<iostream>

using namespace std;


int main(void){
	int b, p;
	long long a;
	cin>>a>>b>>p;
	if(b==0) {
		cout<<1%p<<endl;
		return 0;
	}

	long long res = 1;
	while(b) {
		if(b&1){
			res = res*a % p;
		}
		a = a*a%p;
		b = b>>1;
	}
	cout<<res<<endl;
}
