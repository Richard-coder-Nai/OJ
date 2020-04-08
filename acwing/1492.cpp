#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, d;
bool isPrime(int x){
	if(x==2) return true;
	if(x<2) return false;

	bool flag = true;
	for(int i=2; i<=x/i && flag; i++){
		if(x%i==0) {
			flag = false;
		}
	}
	return flag;
}

bool isRe(int x, int d){

	vector<int> table;
	while(x){
		table.push_back(x%d);
		x = x/d;
	}

	int n = table.size();
	x = 0;
	for(int i=0; i<n; i++){
		x = x*d;
		x += table[i];
	}
	return isPrime(x);
}

int main(void){
	while(true){
		cin>>n;
		if(n<0) {
			break;
		}
		cin>>d;

		bool flag = isPrime(n) && isRe(n, d);
		if(flag) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
}
