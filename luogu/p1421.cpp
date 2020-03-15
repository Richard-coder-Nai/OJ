#include<iostream>
using namespace std;

int n, m;
int main(void){
	cin>>n>>m;
	double money = double(n) + 0.1*double(m);
	cout<<int(money/1.9)<<endl;
}
