#include<iostream>

using namespace std;

int n, m;
int nums[100005];
int k, a, b;

int sum(int i){
	int s = 0;
	while(i){
		s += nums[i];
		i -= i&-i;
	}
	return s;
}

void add(int i, int x){
	while(i<=n){
		nums[i] += x;
		i += i&-i;
	}
}

int main(void){
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		int x;
		cin>>x;
		add(i, x);
	}
	while(m--){
		cin>>k>>a>>b;
		if(k==1){
			add(a, b);
		}else{
			cout<<sum(b)-sum(a-1)<<endl;
		}
	}
}
