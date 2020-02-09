#include<iostream>

using namespace std;


int main(void){
	long long  a, b, p, res = 1;
	cin>>a>>b>>p;
	for(long long i=0; i<b; i++){
		res = res*a%p;
	}
	res = res%p;
	cout<<res<<endl;
}
