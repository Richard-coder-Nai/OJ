#include<iostream>
#include<cmath>

using namespace std;
long long mod = 200907;

int main(void){
	int n;
	cin>>n;
	while(n--){
		long a, b, c;
		int k;
		cin>>a>>b>>c>>k;
		if(b-a==c-b){
			long long d = b-a;
			cout<<(a+d*(k-1))%mod<<endl;
		}else{
			long long q = b/a;
			long res = a;
			k--;
			while(k){
				if(k&1){
					res = res*q%mod;
				}
				k = k>>1;
				q = q*q%mod;
			}
			cout<<res<<endl;
		}
	}
}
