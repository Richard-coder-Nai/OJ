#include<iostream>
#include<cmath>
#include<cstdio>

using namespace std;

bool flag = true;

int main(void){
	double n;
	cin>>n;
	if(n<0) flag = false;
	n = abs(n);
	if(flag==false) cout<<'-';
	printf("%.6f", pow(n, 1.0/3.0));
}

