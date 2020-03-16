#include<bits/stdc++.h>

using namespace std;

const double PI = acos(-1);

struct Complex {
	double r, i;
	Complex() {r = 0; i = 0;};
	Complex(double real, double imag): r(real), i(imag) {}
};

Complex operator + (Complex a, Complex b) { return Complex(a.r + b.r, a.i + b.i);}
Complex operator - (Complex a, Complex b) { return Complex(a.r - b.r, a.i - b.i);}
Complex operator * (Complex a, Complex b) { return Complex(a.r - b.r, a.i - b.i);}





