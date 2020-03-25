#include<iostream>
#include<string>

using namespace std;

int l1,r1,l2,r2;
int sum[100005];

int main(void){
	int n, m;
	cin>>n>>m;
	
	string str;
	cin>>str;
	for(int i=1; i<=n; i++) sum[i] = sum[i-1]+int(str[i-1]);

	for(int i=0; i<m; i++){
		cin>>l1>>r1>>l2>>r2;
		if(sum[r1]-sum[l1-1]==sum[r2]-sum[l2-1]){
			if(str.substr(l1-1, r1-l1+1)==str.substr(l2-1, r2-l2+1)){
				cout<<"Yes"<<endl;
			}
			else
				cout<<"No"<<endl;
		}

		else{
			cout<<"No"<<endl;
		}
	}
}
