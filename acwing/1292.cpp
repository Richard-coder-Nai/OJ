#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

const int N = 1e6;


vector<bool> table(N+1, true);


void build_prim(){
	table[1] = false;
	table[0] = false;
	for(int i=2; i<=N; i++){
		if(table[i]){
			for(int j=2; j<=N/i; j++){
				table[i*j] = false;
			}
		}
	}
}

void Goldbach(int x){
	for(int i=0; ; i++){
		if(i>=x) break;
		if(table[i] && table[x-i]){
			printf("%d = %d + %d\n", x, i, x-i);
			return; 
		}
	}
}


int main(void) {
	build_prim();
	while(true){
		int x;
		cin>>x;
		if(x==0) break;
		Goldbach(x);
	}
}
