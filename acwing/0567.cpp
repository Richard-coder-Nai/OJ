#include<iostream>

using namespace std;

int main(void) {
	int n, m;
	cin>>n>>m;
	if(m<n) {
		cout<<1<<endl;
		return 0;
	}

	int res = 0;
	for(int i=n; i>=1; i--){
		if(m>n){
			res += m/n;
			m = m%n;
			if(m==0) break;
		}
		else{
			res++;
			break;
		}
	}
	cout<<res<<endl;
}
