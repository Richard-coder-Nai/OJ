#include<iostream>

using namespace std;

const int mod = 1e9+7;
const int N = 2010;
int C[N][N];

void init(){
	for(int i=0; i<N; i++){
		for(int j=0; j<=i; j++){
			if(j==0) C[i][j] = 1;
			else{
				C[i][j] = (C[i-1][j-1]+C[i-1][j])%mod;
			}
		}
	}
}

int main(void){
	init();
	int n;
	cin>>n;
	while(n--){
		int a, b;
		cin>>a>>b;
		cout<<C[a][b]<<endl;
	}
}
