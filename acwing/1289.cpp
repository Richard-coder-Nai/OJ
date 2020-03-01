#include<iostream>
#include<cmath>

using namespace std;
long mod = 200907;

int main(void){
	int n;
	cin>>n;
	while(n--){
		int a, b, c, k;
		cin>>a>>b>>c>>k;

		if((b-a)==(c-b)){
			int d = b-a;
			long res = (d*(k-1) + a);
			res = res%mod;
			cout<<res<<endl;
		}else{
			int q = b/a;
			long res = a*pow(q, k-1);
			res = res%mod;
			cout<<res<<endl;
		}
	}
}
