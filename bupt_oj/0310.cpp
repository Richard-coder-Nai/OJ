#include<iostream>

using namespace std;

#define INT_MAX 2147483647

int t, n, m, r;
int memery[105];
bool used[105];

int main(void){
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1; i<=n; i++){
			cin>>memery[i];
			used[i] = false;
		}
		cin>>m;
		for(int i=0; i<m; i++){
			cin>>r;
			int idx = -1;
			int Min = INT_MAX;
			for(int j=1; j<=n; j++){
				if(used[j]==false && memery[j]>=r && Min>memery[j]){
					idx = j;
					Min = memery[j];
				}
			}
			if(idx==-1) cout<<"NULL ";
			else{
				used[idx] = true;
				cout<<memery[idx]<<" ";
			}
		}
		cout<<endl;
	}
}
