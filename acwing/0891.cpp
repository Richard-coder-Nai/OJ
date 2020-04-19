#include<iostream>
#include<vector>

using namespace std;

int n;
int main(void) {
	cin>>n;

	vector<int> table(n, 0);
	for(int i=0; i<n; i++) {
		cin>>table[i];
	}
	int res = table[0];
	for(int i=1; i<n; i++){
		res = res^table[i];
	}
	if(res){
		cout<<"Yes"<<endl;
	}
	else{
		cout<<"No"<<endl;
	}
}
