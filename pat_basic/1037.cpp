#include<cmath>
#include<iostream>

using namespace std;


int main()
{
	int a1,a2,a3;
	int b1,b2,b3;
	scanf("%d.%d.%d %d.%d.%d", &a1, &a2, &a3, &b1, &b2, &b3);

	int a_money = a1*17*29 + a2*29 + a3;
	int b_money = b1*17*29 + b2*29 + b3;

	int change = b_money - a_money;

	if(change<0){
		cout<<"-";
		change=abs(change);
	}

	cout<<int(change/(17*29))<<"."<<change%(17*29)/29<<"."<<change%29<<endl;
}
