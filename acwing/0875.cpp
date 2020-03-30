#include<cmath>
#include<iostream>

using namespace std;


int main(void){
	int n;
	cin>>n;

	while(n--){
		long a, b, p;
		cin>>a>>b>>p;
		long long res = 1;
		while(b){
			if(b&1){
				res = (res*a)%p;
			}
			a = (long long)(a*a)%p;
			b = b>>1;
		}
		cout<<res<<endl;
	}
}
