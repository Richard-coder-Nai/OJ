#include<iostream>
#include<string>

using namespace std;

int main(void){
	string a;
	int b;

	cin>>a>>b;
	if(a=="0"){
		cout<<"0 0"<<endl;
		return 0;
	}

	if(a.length()==1 && a[0]-'0'<b){
		cout<<0<<" "<<a<<endl;
		return 0;
	}

	string result="";
	
	

	int r=0;
	for(auto it=a.begin(); it!=a.end(); it++){
		int n = *it-'0' + r*10;
		r=n%b;	
		n=n/b;
		if(!(it==a.begin() && n==0)){
			result+=to_string(n);
		}
	}
	cout<<result<<" "<<r<<endl;

	return 0;
}
