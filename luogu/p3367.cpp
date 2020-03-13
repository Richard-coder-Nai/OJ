#include<iostream>
#include<cstdio>

using namespace std;

int father[10005];
int n, m;
int opt, x, y;

void init(){
	for(int i=0; i<=n; i++){
		father[i] = i;
	}
}

int find_father(int x){
	int a = x;
	while(x!=father[x]){
		x = father[x];
	}
	while(a!=x){
		int z = father[a];
		father[a] = x;
		a = z;
	}
	return x;
}

void Union(int x, int y){
	int fx = find_father(x);
	int fy = find_father(y);
	if(fx!=fy){
		father[fx] = fy;
	}
}

int main(void){
	cin>>n>>m;
	init();
	while(m--){
		scanf("%d%d%d", &opt, &x, &y);
		if(opt==1){
			Union(x, y);
		}else{
			int fx = find_father(x);
			int fy = find_father(y);
			if(fx!=fy) cout<<'N'<<endl;
			else cout<<'Y'<<endl;
		}
	}
}
