#include<iostream>
#include<cmath>

using namespace std;

int n;
int main(void) {
	cin>>n;
	int d = log(n+1)/log(2);
	int res = 0;
	int cnt = 0;
	long long cmp = -1112120;
	long long tmp = 0;
	for(int i=1; i<=d; i++){
		int k = pow(2, i-1);
		int x;
		tmp = 0;
		for(int j=0; j<k; j++){
			cnt ++;
			cin>>x;
			tmp += x;
		}
		if(cmp<tmp){
			res = i;
			cmp = tmp;
		}
	}
	tmp = 0;
	for(int i=cnt; i<n; i++){
		int x; 
		cin>>x;
		tmp += x;
	}
	if(cmp<tmp){
		res = d+1;;
	}
	cout<<res<<endl;
}

