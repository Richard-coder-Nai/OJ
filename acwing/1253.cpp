#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

int father[10005];
unordered_map<string, int> name2idx;
unordered_map<int, string> idx2name;

string Data;
string cur_f, cur_son; //current father;

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

int main(void){
	int idx = 1;
	while(true){
		cin>>Data;
		if(Data[0]=='#'){
			cur_f = string(Data.begin()+1, Data.end());
			if(name2idx.count(cur_f)==false){
				father[idx] = idx;
				name2idx[cur_f] = idx;
				idx2name[idx] = cur_f;
				idx++;
			}
		}
		if(Data[0]=='+'){
			cur_son = string(Data.begin()+1, Data.end());
			if(name2idx.count(cur_son)==false){
				name2idx[cur_son] = idx;
				idx2name[idx] = cur_son;
				idx++;
			}
			father[name2idx[cur_son]] = name2idx[cur_f];
		}
		if(Data[0]=='?'){
			string cur(Data.begin()+1, Data.end());
			cout<<cur<<" ";
			cout<<idx2name[find_father(name2idx[cur])]<<endl;
		}
		if(Data[0]=='$') return 0;
	}
	return 0;
}
