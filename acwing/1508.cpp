#include <iostream>

using namespace std;


int main(void) {
	int t;
	cin>>t;

	int n1=0, n2=0;
	for(int i=0; i<t; i++) {
		int x, y;
		cin>>x>>y;

		if(x==y) continue;

		if(x!=20 && y!=20) {
			if(x>y) n1+=(x-y);
			if(x<y) n2+=(y-x);
		}

		if(x==20 && (y==5||y==10)) n2 += 10;
		if(y==20 && (x==5||x==10)) n1 += 10;

		if(x==20 && y==15) n1 += 5;
		if(y==20 && x==15) n2 += 5;

	}
	cout<<n1<<" "<<n2<<endl;
}
