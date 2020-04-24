#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string str;
	getline(cin, str);

	for(char& it:str){
		if(it>='a'&&it<'z'){
			it++;
		}
		else if(it=='z') it = 'a';
		if(it>='A'&&it<'Z'){
			it++;
		}
		else if(it=='Z') it = 'A';
	}
	cout<<str<<endl;
}
