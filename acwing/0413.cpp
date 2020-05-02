#include <iostream>
#include <cmath>

using namespace std;

string tmp;
string str = "";

int  main(void) {
	while(cin>>tmp) {
		str += tmp;
	}


	int n = str.size();
	int a=0, b=0;

	for(int i=0; i<n && str[i]!='E'; i++) {
		if(str[i]=='W') a++;
		else b++;

		if(max(a, b)>=11 && abs(a-b)>=2) {
			cout<<a<<":"<<b<<endl;
			a = 0;
			b = 0;
		}
	}
	cout<<a<<":"<<b<<endl<<endl;

	a = 0;
	b = 0;
	for(int i=0; i<n && str[i]!='E'; i++) {
		if(str[i]=='W') a++;
		else b++;
		if(max(a, b)>=21 && abs(a-b)>=2) {
			cout<<a<<":"<<b<<endl;
			a = 0;
			b = 0;
		}
	}
	cout<<a<<":"<<b<<endl;
}
