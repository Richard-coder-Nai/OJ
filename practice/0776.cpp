#include<iostream>
#include<string>

using namespace std;

int main(void) {
	string s1;
	string s2;
	cin>>s1>>s2;
	if(s1.size()<s2.size()) swap(s1, s2);
	s1 = s1+s1;
	int pos = s1.find(s2);
	if(pos!=s1.npos){
		cout<<"true"<<endl;
	}else{
		cout<<"false"<<endl;
	}
}
