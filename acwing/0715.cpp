#include<iostream>

using namespace std;

int main(void){
	int n;
	scanf("%d", &n);
	for(int i=2; i<=10000; i++){
		if(i%n==2) printf("%d\n", i);
	}
}
