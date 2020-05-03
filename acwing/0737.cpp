#include <iostream>

using namespace std;

int nums[10];

int main(void) {
	for(int i=0; i<10; i++) {
		cin>>nums[i];
		if(nums[i]<=0) nums[i] = 1;
	}

	for(int i=0; i<10; i++) {
		cout<<"X["<<i<<"] = "<<nums[i]<<endl;
	}
}

