#include<iostream>
#include<bitset>
#include<string>

using namespace std;


int main(void){
	bitset<32> bs(10);
	cout<<bs<<endl;
	cout<<bs.count()<<endl;
	cout<<bs.to_ulong()<<endl;
	cout<<bs.to_string()<<endl;
}
