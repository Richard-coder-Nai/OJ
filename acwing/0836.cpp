#include<iostream>

using namespace std;

int father[100005];
int n,m;


int find_father(int x){
	int a = x;
	while(x!=father[x]){
		x = father[x];
	}
	// zip
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

void init(){
	for(int i=1; i<=n; i++){
		father[i] = i;
	}
}

int main(void){
	cin>>n>>m;
	init();

	int n1, n2;
	char opt;
	for(int i=0; i<m; i++){
		cin>>opt>>n1>>n2;
		if(opt=='M') Union(n1, n2);
		if(opt=='Q'){
			int f1 = find_father(n1);
			int f2 = find_father(n2);
			if(f1==f2) cout<<"Yes"<<endl;
			else cout<<"No"<<endl;
		}
	}
}

