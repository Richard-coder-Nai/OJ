#include <iostream>

using namespace std;

bool isPrim(int x) {
	if(x<2) return false;
	if(x==2) return true;
	for(int i=2; i<=x/i; i++) {
		if(x%i==0) return false;
	}
	return true;
}

int main(void) {
	int n;
	cin>>n;
	while(n--) {
		int x;
		cin>>x;
		if(isPrim(x)) {
			cout<<"Yes"<<endl;
		}else{
			cout<<"No"<<endl;
		}
	}
}
