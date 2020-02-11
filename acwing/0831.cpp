#include<iostream>
#include<string>

using namespace std;

int n;
string s;
string p;

int main(void){
	cin>>n;
	cin>>p;
	cin>>n;
	cin>>s;
	
	long pos = 0;
	while(1){
		pos=s.find(p, pos);
		if(pos==s.npos) break;
		cout<<pos<<" ";
		pos++;
	}
	cout<<endl;
}
