#include<iostream>

using namespace std;

int Time[105];
int value[105];

int f[1005];

int main(void){
	int T, M;
	cin>>T>>M;

	for(int i=1; i<=M; i++) {
		cin>>Time[i]>>value[i];
	}

	for(int i=1; i<=M; i++) {
		for(int t=T; t>=Time[i]; t--){
			f[t] = max(f[t], f[t-Time[i]]+value[i]);
		}
	}
	cout<<f[T]<<endl;
}
