#include<iostream>

using namespace std;

int ways[3005];

int main(void){
	int n,m;
	cin>>n>>m;
	ways[0] = 1;
	for(int i=0; i<n; i++){
		int tmp;
		cin>>tmp;
		for(int i=tmp; i<=m; i++){
			ways[i] += ways[i-tmp];
		}
	}
	cout<<ways[m]<<endl;
}
