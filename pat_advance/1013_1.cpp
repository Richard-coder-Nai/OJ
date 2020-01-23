#include<iostream>
#include<vector>
#include<list>

using namespace std;


vector<int> father;
vector<bool> visited;
vector<list<int>> adj;
int del_city;

int find_father(int x){
	int a = father[x];
	while(x!=father[x]){
		x = father[x];
	}

	//zip
	while(a!=father[x]){
		int z = a;
		a = father[x];
		father[z] = x;
	}
	return x;
}

void Union(int x, int y){
	int f_x = find_father(x);
	int f_y = find_father(y);

	if(f_x!=f_y){
		father[f_x] = f_y;
	}
}

void init(int n){
	adj.assign(n, list<int>());
	for(int i=0; i<n; i++){
		father[i] = i;
		visited[i] = false;
	}
}

int main(void){
	int n,e,k;
	cin>>n>>e>>k;

	init(n);

	for(int i=0; i<e; i++){
		int n1, n2;
		cin>>n1>>n2;
		adj[n1].push_back(n2);
		adj[n2].push_back(n1);
	}

	

	for(int i=0; i<k; i++){
		cin>>del_city;
		for(int i=0; i<n; i++){
			for(auto it: adj[i]){
				if(i==del_city||it==del_city) continue;
				Union(i, it);
			}
		}
	}
}
