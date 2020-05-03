#include <iostream>
#include <cstdio>

using namespace std;

const double pi = 3.14159;

int main(void) {
	double res;
	cin>>res;
	res = pi*res*res;
	printf("A=%.4f\n", res);
}
