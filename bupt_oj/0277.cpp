#include<iostream>

using namespace std;

int memery[105];
bool used[105];
int m, request, n;

int main(void){
	int t;
	cin>>t;

	while(t--){
		cin>>n;
		for(int i=1; i<=n; i++){
			cin>>memery[i];
			used[i] = false;
		}
		cin>>m;
		int idx = -1;
		int min = INT_MAX;
		for(int i=1; i<=n; i++){
			cin>>request;
		}
		if(idx==-1) cout<<"NULL"<<endl;
	}
}
