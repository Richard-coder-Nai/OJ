#include<iostream>

using namespace std;

int a, n;
int main(void){
	cin>>a;
	while(cin>>n){
		if(n>0){
			break;
		}
	}
	cout<<(a+a+n-1)*n/2<<endl;
}
