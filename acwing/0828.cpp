#include<iostream>
#include<string>
#include<stack>

using namespace std;

string opt;
int n;
int k;

int main(void){
	cin>>n;
	stack<int> stk;

	for(int i=0; i<n; i++){
		cin>>opt;
		if(opt=="push"){
			cin>>k;
			stk.push(k);
		}
		if(opt=="pop"){
			stk.pop();
		}
		if(opt=="query"){
			cout<<stk.top()<<endl;
		}
		if(opt=="empty"){
			if(stk.empty()) cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}
	}
}
