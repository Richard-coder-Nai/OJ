#include<iostream>

using namespace std;

int x;
int main(void){
	cin>>x;
	for(int i=1; i<=x; i++)
		if(i%2) cout<<i<<endl;
}
