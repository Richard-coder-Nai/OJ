#include<iostream>
#include<string>
#include<algorithm>

using namespace std;


int main(void){
	string n1, n2;
	cin>>n1>>n2;

	reverse(n1.begin(), n1.end());
	reverse(n2.begin(), n2.end());

	int p = 0;
	int carry = 0;
	string res = "";

	while(p<n1.size()||p<n2.size()){
		int cur = carry;
		if(p<n1.size()) cur += (n1[p]-'0');
		if(p<n2.size()) cur += (n2[p]-'0');
		carry = 0;
		if(cur>=10){
			carry = 1;
			cur = cur%10;
		}
		res += char(cur+'0');
		p++;
	}
	if(carry){
		res+="1";
	}

	reverse(res.begin(), res.end());
	cout<<res<<endl;
}
