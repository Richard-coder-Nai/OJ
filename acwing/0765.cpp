#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string str;
	getline(cin, str);
	for(auto it:str){
		cout<<it<<" ";
	}
	cout<<endl;
}
