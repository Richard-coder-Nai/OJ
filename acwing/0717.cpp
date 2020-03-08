#include<iostream>

using namespace std;

int f[50];

int main(void){
	int n;
	cin>>n;

	f[0] = 0;
	f[1] = 1;

	for(int i=2; i<n; i++){
		f[i] = f[i-1]+f[i-2];
	}

	for(int i=0; i<n; i++){
		cout<<f[i]<<" ";
	}
	cout<<endl;
}
