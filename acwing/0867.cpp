#include<iostream>

using namespace std;

int main(void){
	int n;
	cin>>n;

	while(n--){
		int k;
		cin>>k;
		for(int i=2; i<=k; i++){
			if(k%i==0){
				int s = 0;
				while(k%i==0){
					s++;
					k /= i;
				}
				cout<<i<<" "<<s<<endl;
			}
		}
		cout<<endl;
	}
}

