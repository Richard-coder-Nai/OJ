#include<iostream>

using namespace std;

int n;
int main(void){
	while(true){
		cin>>n;
		if(n==0) break;
		for(int i=1; i<=n; i++) cout<<i<<" ";
		cout<<endl;
	}
}
