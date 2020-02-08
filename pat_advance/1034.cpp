#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<set>

using namespace std;

vector<int> father;


int find_father(int n){
	int a = n;
	while(n != father[n]){
		n = father[n];
	}

	while(a != father[n]){
		int z = father[a];
		father[a] = n;
		a = z;
	}
	return n;
}


void Union(int n1, int n2){
	int f1 = find_father(n1);
	int f2 = find_father(n2);

	if(f1 != f2){
		father[f1] = f2;
	}
}


int main(void){

	int n,k;
	cin>>n>>k;

	map<int, string> index2name;
	map<string, int> name2index;


	vector<int> time_table;

	int index=0;

	for(int i=0; i<n; i++){
		string src, dest;
		int time;
		cin>>src>>dest>>time;

		if(name2index.count(src)==false){
			name2index[src]=index;
			index2name[index]=src;
			time_table.push_back(time);
			father.push_back(index);
			index++;
		}else{
			int idx = name2index[src];
			time_table[idx] += time;
		}
		if(name2index.count(dest)==false){
			name2index[dest]=index;
			index2name[index]=src;
			time_table.push_back(time);
			father.push_back(index);
			index++;
		}else{
			int idx = name2index[dest];
			time_table[idx] += time;
		}
		Union(name2index[src], name2index[dest]);
	}

	map<int, int> counter;
	for(int i=0; i<name2index.size(); i++){
		int f = find_father(i);

	}
}
