#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

vector<int> father;

void init(int n){
	for(int i=0; i<=n; i++){
		father.push_back(i);
	}
}

int course[1001] = {0};

int find_father(int n){
	int a = n;
	while(n!=father[n]){
		n = father[n];
	}

	while(a!=father[n]){
		int z = a;
		a = father[a];
		father[z] = n;
	}
	
	return n;
}

void Union(int x1, int x2){
	int f1 = find_father(x1);
	int f2 = find_father(x2);
	if(f1!=f2){
		father[f1] = f2;
	}
}


int main(void){
	int n;
	cin>>n;
	init(n);

	map<int, int> name2hobby;

	for(int i=1; i<=n; i++){
		int k;
		scanf("%d:", &k);
		for(int j=0; j<k; j++){
			int hobby;
			cin>>hobby;

			if(course[hobby] == 0)
				course[hobby] = i;
			else{
				Union(i, course[hobby]);
			}
		}
	}
	
	map<int, int> table;
	for(int i=1; i<=n; i++){
		int f = find_father(i);

		if(table.count(f)){
			table[f] += 1;
		}else{
			table[f] = 1;
		}
	}
	cout<<table.size()<<endl;

	vector<int> out;
	for(auto it:table){
		out.push_back(it.second);
	}
	
	sort(out.begin(), out.end());
	reverse(out.begin(), out.end());

	bool first = true;
	for(auto it:out){
		if(first == false) cout<<" ";
		cout<<it;
		first = false;
	}
}
