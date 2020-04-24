#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void) {
	string str1, str2;
	getline(cin, str1);
	getline(cin, str2);
	transform(str1.begin(), str1.end(), str1.begin(),::tolower);
	transform(str2.begin(), str2.end(), str2.begin(),::tolower);

	int len = min(str1.size(), str2.size());
	int idx = 0;
	while(idx<len){
		if(str1[idx]==str2[idx]){
			idx++;
		}
		if(str1[idx]>str2[idx]){
			cout<<">"<<endl;
			return 0;
		}
		if(str1[idx]<str2[idx]){
			cout<<"<"<<endl;
			return 0;
		}
	}
	cout<<"="<<endl;
}
