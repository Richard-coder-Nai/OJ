#include<iostream>
#include<vector>
#include<map>

using namespace std;


vector<int> father;
map<string, int> name2index;

int find_father(int x){
	int a = x;
	while(x!=father[x]){
		x = father[x];
	}

	while(a!=father[x]){
		int z = a;
		a = father[a];
		father[z] = x;
	}

	return x;
}

void Union(string name1, string name2){
	int n1 = name2index[name1];
	int n2 = name2index[name2];
	int fa_n1 = find_father(n1);
	int fa_n2 = find_father(n2);

	if(fa_n1!=fa_n2){
		father[fa_n1] = fa_n2;
	}
}

bool Find(string name1, string name2){
	int n1 = name2index[name1];
	int n2 = name2index[name2];
	int fa_n1 = find_father(n1);
	int fa_n2 = find_father(n2);

	if(fa_n1!=fa_n2){
		return false;
	}else{
		return true;
	}
}



int main(){
	int name_num, opt_num;
	cin>>name_num>>opt_num;

	father.assign(name_num, 0);

	for(int i=0; i<name_num; i++){
		string name;
		cin>>name;
		name2index[name] = i;
		father[i] = i;
	}

	for(int i=0; i<opt_num; i++){
		int opt;
		cin>>opt;
		string name1, name2;
		cin>>name1>>name2;

		if(opt==1){
			Union(name1, name2);
		}else{
			if(Find(name1, name2)){
				cout<<1<<endl;
			}else{
				cout<<0<<endl;
			}
		}
	}
}
