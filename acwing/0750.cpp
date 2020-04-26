#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	char opt;
	cin>>opt;
	double sum = 0;
	for(int i=0; i<144; i++) {
		double x;
		cin>>x;
		sum += x;
	}

	if(opt=='S') {
		cout<<sum<<endl;
	}else{
		cout<<sum/144<<endl;
	}
}
