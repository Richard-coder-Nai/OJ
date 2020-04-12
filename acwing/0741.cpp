#include<iostream>
#include<vector>

using namespace std;

vector<long long> build_fib(){
	vector<long long> fib(61, 0);
	fib[1] = 1;
	fib[2] = 1;
	for(int i=2; i<=60; i++){
		fib[i] = fib[i-1]+fib[i-2];
	}
	return fib;
}

int main(void) {
	vector<long long> fib = build_fib();
	int n;
	cin>>n;
	for(int i=0; i<n; i++){
		int k;
		cin>>k;
		cout<<"Fib("<<k<<") = "<<fib[k]<<endl;;
	}
}
