#include<iostream>

using namespace std;


int main(void){
	pair<int, int> test;
	test.first = 1;
	
	cout<<test.first<<endl;
	test = make_pair(1, 2);
	cout<<test.first<<" "<<test.second<<endl;
}
