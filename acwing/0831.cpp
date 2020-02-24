#include<iostream>
#include<string>

using namespace std;

int n;
string s1;
string s2;

int main(void){
	cin>>n;
	cin>>s1;
	cin>>n;
	cin>>s2;

	int pos = 0;
	while(true){
		pos = s2.find(s1, pos);
		if(pos == s2.npos){
			cout<<endl;
			return 0;
		}
		cout<<pos<<" ";
		pos++;
	}
}
