#include<iostream>
#include<queue>

using namespace std;

int n, k;
queue<int> q;
string opt;

int main(void){
	cin>>n;

	for(int i=0; i<n; i++){
		cin>>opt;
		if(opt=="push"){
			cin>>k;
			q.push(k);
		}
		if(opt=="pop"){
			q.pop();
		}
		if(opt=="empty"){
			if(q.empty()) cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}
		if(opt=="query"){
			cout<<q.front()<<endl;
		}
	}
}
