#include<iostream>

using namespace std;

int h1, h2, m1, m2;
int main(void){
	cin>>h1>>m1;
	cin>>h2>>m2;

	if(m2>m1){
		cout<<h2-h1<<" "<<m2-m1<<endl;
	}else{
		cout<<-1+h2-h1<<" "<<60+m2-m1<<endl;
	}
}
