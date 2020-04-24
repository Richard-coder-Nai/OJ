#include <iostream>

using namespace std;

double k;
string str1, str2;

int main(void) {
	cin>>k;
	cin>>str1>>str2;

	int n = str1.size();
	int match = 0;
	for(int i=0; i<n; i++) {
		if(str1[i]==str2[i]) match++;
	}

	if(double(match)/double(n)-k>=0) cout<<"yes"<<endl;
	else cout<<"no"<<endl;
}

