#include<iostream>

using namespace std;

int n, m;

int father[20005];

void init(){
	for(int i=0; i<=n; i++) father[i] = i;
}

int find_father(int x){
	int a = x;
	while(x!=father[x]) x = father[x];

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
	if(fx!=fy) father[fx] = fy;
}


int x, y;
int main(void){
	cin>>n>>m;
	init();
	while(m--){
		cin>>x>>y;
		Union(x, y);
	}

	for(int i=1; i<=n; i++) find_father(i);

	int q;
	cin>>q;
	while(q--){
		cin>>x>>y;
		int fx = father[x];
		int fy = father[y];
		if(fx==fy) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
}
