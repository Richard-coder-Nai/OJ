#include<iostream>
#include<vector>

using namespace std;


int main(void){
	int n;
	cin>>n;
	if(n<2){
		cout<<0<<endl;
		return 0;
	}
	if(n==2) {
		cout<<1<<endl;
		return 0;
	}

	vector<bool> table(n+1, true);
	table[0] = false;
	table[1] = false;

	for(int i=2; i*i<=n; i++){
		if(table[i]==true){
			for(int j=2; i*j<=n; j++){
				table[i*j] = false;
			}
		}
	}


	int counter = 0;
	for(int i=0; i<=n; i++){
		if(table[i]) counter++;
	}
	cout<<counter<<endl;
}
