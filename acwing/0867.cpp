#include<iostream>

using namespace std;


void get_nums(int n){
	for(int i=2; i*i<=n; i++){
		if(n%i==0){
			int s = 0;
			while(n%i==0){
				s++;
				n = n/i;
			}
			cout<<i<<' '<<s<<endl;
		}
	}
	if(n>1) cout<<n<<' '<<1<<endl;
}

int main(void){
	int n, t;
	cin>>t;
	while(t--){
		cin>>n;
		get_nums(n);
		cout<<endl;
	}
}

