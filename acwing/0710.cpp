#include<iostream>
#include<cstdio>

using namespace std;

int main(void){
	int n;
	int cnt = 6;
	scanf("%d", &n);
	if(n%2==0){
		n++;
	}
	while(cnt--){
		printf("%d\n", n);
		n+=2;
	}
}
