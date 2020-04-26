#include <iostream>
#include <stack>

using namespace std;

stack<int> stk;
int n;

int main(void) {
	cin>>n;
	for(int i=0; i<n; i++){
		int x;
		cin>>x;
		while(stk.empty()==false && stk.top()>=x) {
			stk.pop();
		}
		if(stk.empty()) cout<<-1<<endl;
		else cout<<stk.top()<<endl;
		stk.push(x);
	}
}
