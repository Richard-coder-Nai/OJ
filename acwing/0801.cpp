#include<iostream>
#include<bitset>

using namespace std;

int tmp;

int main(void){
	int n;
	cin>>n;

	for(int i=0; i<n; i++){
		cin>>tmp;
		bitset<32> bs(tmp);
		cout<<bs.count()<<" ";
	}
	cout<<endl;
}
