#include<iostream>

using namespace std;

int n;

int main(void){
	cin>>n;

	for(int i=0; i<n; i++){
		int k;
		cin>>k;
		if(k==0 || k==1){
			cout<<"No"<<endl;
			continue;
		}

		if(k==2){
			cout<<"Yes"<<endl;
			continue;
		}
		bool isprime = true;
		for(int i=2; i*i<=k; i++){
			if(k%i==0){
				isprime = false;
				break;
			}
		}

		if(isprime){
			cout<<"Yes"<<endl;
		}else{
			cout<<"No"<<endl;
		}
	}
}
