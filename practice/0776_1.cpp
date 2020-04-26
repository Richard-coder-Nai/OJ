#include <iostream>

using namespace std;

int main(void) {
	string a, b;
	cin>>a>>b;
	if(a.size()<b.size()) swap(a, b);
	a = a+a;
	if(a.find(b)!=a.npos) cout<<"true"<<endl;
	else cout<<"false"<<endl;
}
