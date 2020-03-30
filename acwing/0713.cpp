#include<iostream>

using namespace std;

int main(void){
	int n, x;
	cin>>n;

	int in = 0;
	int out = n;

	while(n--){
		cin>>x;
		if(x>=10 && x<=20) in++;
	}
	cout<<in<<" in"<<endl;
	cout<<out-in<<" out"<<endl;
}
