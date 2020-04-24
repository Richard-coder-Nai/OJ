#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main(void) {
	string s, s1, s2;

	getline(cin, s);
	cin>>s1>>s2;

	cout<<regex_replace(s, regex("\\b"+s1+"\\b"), s2)<<endl;
}

