#include<iostream>
#include<string>
using namespace std;

int main(void){
	long a, b;
	cin>>a>>b;
	string res = to_string(a+b);
	int n = res.size();
	bool flag = false;
	for(int i=0; i<n; i++){
		if((n-i)%3==0 && flag==true) cout<<",";
		cout<<res[i];
		if(res[i]!='-')
			flag = true;
	}
	cout<<endl;
}
