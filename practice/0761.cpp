#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string str;
	getline(cin, str);

	int cnt = 0;
	for(char it:str) {
		if(it>='0' && it<='9') cnt++;
	}
	cout<<cnt<<endl;
}
