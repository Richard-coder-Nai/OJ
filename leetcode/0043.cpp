#include<string>
#include<iostream>
#include<algorithm>

using namespace std;



string single_mul(string num, char c, int shift){
	if(c=='0') return "0";

	reverse(num.begin(), num.end());

	int n=c-'0';
	int carry=0;
	for(int i=0; i<num.size(); i++){
		int tmp=carry;
		tmp=tmp+(num[i]-'0')*n;
		carry=tmp/10;
		num[i]=char(tmp%10+'0');
	}
	if(carry)
		num+=to_string(carry);
	reverse(num.begin(), num.end());
	for(int i=0; i<shift; i++){
		num+="0";
	}
	return num;
}

string adder(string num1, string num2){
	reverse(num1.begin(), num1.end());
	reverse(num2.begin(), num2.end());
	string result="";
	int length=num1.size()>num2.size()?num1.size():num2.size();
	int carry=0;
	for(int i=0; i<length; i++){
		int tmp=carry;
		if(i<num1.size()){
			tmp=tmp+num1[i]-'0';
		}
		if(i<num2.size()){
			tmp=tmp+num2[i]-'0';
		}
		if(tmp>=10){
			carry=1;
			tmp=tmp%10;
		}else{
			carry=0;
		}
		result+=to_string(tmp);
	}
	if(carry){
		result+="1";
	}
	reverse(result.begin(), result.end());
	return result;
}

string multiply(string num1, string num2){
	string big;
	string small;
	if(num1.size()>num2.size()){
		big=num1;
		small=num2;
	}else{
		big=num2;
		small=num1;
	}
	
	string result=single_mul(big, *(small.end()-1), 0);
	for(int i=small.size()-2; i>=0; i--){
		string tmp=single_mul(big, small[i], small.size()-1-i);
		result=adder(result, tmp);
	}
	return result;
}

int main(void){
	string num1, num2;
	cin>>num1>>num2;
	cout<<multiply(num1, num2)<<endl;
	//cout<<single_mul("9", '0', 1)<<endl;
	//cout<<adder(num1, num2)<<endl;
	//cout<<multipy(num1, num2)<<endl;
}
