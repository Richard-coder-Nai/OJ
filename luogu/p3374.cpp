#include<iostream>
#include<cstdio>

using namespace std;

int a[500005];

int n, m;
int opt, x, k;



int add(int x, int k){
	while(x<=n){
		a[x] += k;
		x += x&-x;
	}
}

int sum(int x){
	int s = 0;
	while(x){
		s += a[x];
		x -= x&-x;
	}
	return s;
}

int main(void){
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		int tmp;
		scanf("%d", &tmp);
		add(i, tmp);
	}
	for(int i=0; i<m; i++){
		scanf("%d %d %d", &opt, &x, &k);
		if(opt==1){
			add(x, k);
		}
		else{
			int res = sum(k)-sum(x-1);
			printf("%d\n", res);
		}
	}
}
