#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

string path;
int main(void){
	while(cin>>path){
		reverse(path.begin(), path.end());
		int pos = path.find('\\');
		cout<<pos<<endl;
	}
}
