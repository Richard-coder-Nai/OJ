#include<iostream>

using namespace std;

int Time[105];
int value[105];

int f[1005];

int main(void){
	int T, n;
	cin>>T>>n;
	for(int i=0; i<n; i++){
		cin>>Time[i]>>value[i];
	}


	for(int i=0; i<=T; i++){
		for(int j=0; j<n; j++){
			if(i-Time[j]>=0){
				f[i] = max(f[i], f[i-Time[j]]+value[j]);
			}
		}
	}
	cout<<f[T]<<endl;
}
