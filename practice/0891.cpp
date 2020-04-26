#include <iostream>

using namespace std;

int main(void) {
	int n;
	cin>>n;
	int res = 0;
	for(int i=0; i<n; i++) {
		int x;
		cin>>x;
		res = res^x;
	}
	if(res) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
}
