#include<iostream>

using namespace std;


int main(void) {
	int n;
	cin>>n;
	int res = 0;
	for(int i=1; i<=n; i++) {
		int a;
		cin>>a;
		if(i%2) res = res^a;
	}
	if(res==0){
		cout<<"No"<<endl;
	}
	else{
		cout<<"Yes"<<endl;
	}
	return 0;
}
