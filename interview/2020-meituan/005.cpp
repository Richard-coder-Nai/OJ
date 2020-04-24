#include<iostream>
#include<string>

using namespace std;

string str;

int main(void){
	while(cin>>str){
		char cur = str[0];
		int cnt = 1;
		int n = str.size();
		bool flag = false;
		for(int i=1; i<n; i++){
			if(str[i]==cur) cnt++;
			else{
				if(cnt==1) cout<<cur, flag = true;
				cur = str[i];
				cnt = 1;
			}
		}
		if(cnt==1) cout<<cur;
		else if(flag==false) cout<<"no";
		cout<<endl;
	}
}
