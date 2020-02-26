#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int main(void){
	string n1;
	string n2;

	cin>>n1>>n2;

	bool neg = false;

	if(n1==n2) {
		cout<<0<<endl;
		return 0;
	}

	if(n1.length()<n2.length()){
		neg = true;
		swap(n1, n2);
	}

	if(n1.length()==n2.length()){
		int x = 0;
		while(n1[x]==n2[x]){
			x++;
		}

		if(n1[x]<n2[x]){
			neg = true;
			swap(n1, n2);
		}
	}

	reverse(n1.begin(), n1.end());
	reverse(n2.begin(), n2.end());

	int p = 0;
	string res = "";
	int carry = 0;

	while(p<n1.size()){
		int cur = n1[p]+carry-'0';
		if(p<n2.size())
			cur -= (n2[p]-'0');
		carry = 0;
		if(cur<0){
			carry = -1;
			cur += 10;
		}
		res += char(cur+'0');
		p++;
	}
	reverse(res.begin(), res.end());

	for(int i=0; i<res.size(); i++){
		if(res[i]!='0'){
			res = string(res.begin()+i, res.end());
			break;
		}
	}

	if(neg)
		res = '-' + res;
	cout<<res;
}
