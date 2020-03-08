#include<iostream>

using namespace std;

int n, t;

int get_nums(int n){
	int ans = 1;
	for(int i=2; i*i<=n; i++){
		if(n%i==0){
			int s = 0;
			while(n%i==0){
				s++;
				n = n/i;
			}
			ans = ans*(s+1);
		}
	}
	if(n>1) ans *= 2;
	return ans;
}

int main(void){
	cin>>t;

	while(t--){
		cin>>n;
		cout<<get_nums(n)<<endl;
	}
}

