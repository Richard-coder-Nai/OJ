#include<iostream>

using namespace std;

int n, x;

int ans = 0;

int counter(int i){
	while(i){
		if(i%10==x) ans++;
		i /= 10;
	}
}


int main(void){
	cin>>n>>x;
	for(int i=1; i<=n; i++){
		counter(i);
	}
	cout<<ans<<endl;
}
