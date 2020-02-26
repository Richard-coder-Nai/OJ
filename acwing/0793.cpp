#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

string mul(string a, char b, int shift){
	int m = b-'0';
	reverse(a.begin(), a.end());
	string res="";

	int carry = 0;

	int p = 0;
	while(p<a.size()){
		int cur = carry;
		cur += m*(a[p]-'0');
		carry = 0;
		if(cur>=10){
			carry = cur/10;
			cur = cur%10;
		}
		res += to_string(cur);
		p++;
	}
	if(carry>0){
		res += to_string(carry);
	}

	reverse(res.begin(), res.end());
	while(shift--){
		res += "0";
	}
	return res;
}

string add(string a, string b){
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	int p = 0;
	int carry = 0;
	string res = "";
	while(p<a.size()||p<b.size()){
		int cur = carry;
		if(p<a.size()){
			cur += (a[p]-'0');
		}
		if(p<b.size()){
			cur += (b[p]-'0');
		}
		carry = 0;
		if(cur>=10){
			carry = 1;
			cur %= 10;
		}
		res += to_string(cur);
		p++;
	}
	if(carry>0) res += "1";
	reverse(res.begin(), res.end());
	return res;
}


int main(void){
	string a, b;
	cin>>a>>b;

	string res = "";
	for(int i=0; i<b.size(); i++){
		string tmp = mul(a, b[i], b.size()-i-1);
		res = add(res, tmp);
	}
	cout<<res<<endl;
}
