#include<iostream>

using namespace std;

double x;
int main(void){
	for(int i=0; i<100; i++){
		cin>>x;
		if(x<=10){
			printf("A[%d] = %.1f\n", i, x);
		}
	}
}
