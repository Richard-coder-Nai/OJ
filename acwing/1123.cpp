#include<iostream>
#include<cmath>

using namespace std;

int main(void){
	double x1, x2, y1, y2;
	cin>>x1>>x2;
	double sum = 0;
	while(cin>>x1>>y1>>x2>>y2){
		double dx = x1-x2;
		double dy = y1-y2;
		sum += 2*sqrt(dx*dx+dy*dy);
	}

	int minitue = round(sum/1000*60/20);
	int hours = minitue/60;
	minitue = minitue%60;
	printf("%d:%02d\n", hours, minitue);
}
