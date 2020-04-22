#include<iostream>
#include<set>

using namespace std;

int main(void){
	int n;
	cin>>n;

	char opt;
	int num;
	set<int> table;
	for(int i=0; i<n; i++){
		cin>>opt>>num;
		if(opt=='I'){
			table.insert(num);
		}
		if(opt==''){
	}
}
