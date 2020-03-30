#include<iostream>
#include<string>

using namespace std;

string str1, str2;
int main(void){
	cin>>str1>>str2;
	if(str1.size()<str2.size()) swap(str2, str1);
	str1 = str1+str1;
	int pos = str1.find(str2);
	if(pos!=str2.npos) cout<<"true"<<endl;
	else cout<<"false"<<endl;
}
