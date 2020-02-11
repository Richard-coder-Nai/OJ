#include<iostream>
#include<string>

using namespace std;

int n,m;
int father[100005];

void init(){
	for(int i=1; i<=n; i++){
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

	string opt;
	for(int i=0; i<m; i++){
		cin>>opt;
		if(opt=="C"){
			int n1, n2;
			cin>>n1>>n2;
			Union(n1, n2);
		}

		if(opt=="Q1"){
			int n1, n2;
			cin>>n1>>n2;
			int f1 = find_father(n1);
			int f2 = find_father(n2);
			if(f1!=f2) cout<<"No"<<endl;
			else cout<<"Yes"<<endl;
		}

		if(opt=="Q2"){
			int n1;
			cin>>n1;
			int counter = 0;
			int f = find_father(n1);

			for(int j=1; j<=n; j++){
				if(f==find_father(j)) 
					counter++;
			}
			cout<<counter<<endl;
		}
	}
}
