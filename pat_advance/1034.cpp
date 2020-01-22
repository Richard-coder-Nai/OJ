#include<iostream>
#include<map>
#include<string>
#include<vector>

using namespace std;


int main(void){
	int n,k;
	cin>>n>>k;

	map<int, string> index2name;
	map<string, int> name2index;

	vector<vector<int>> g(2000, vetor<int>(0));

	int index=0;

	for(int i=0; i<n; i++){
		string src, dest;
		int time;
		cin>>src>>dest>>time;

		if(name2index.count(src)==false){
			name2index[src]=index;
			index2name[index]=src;
			index++;
		}else{
			int tmp=name2index[src];
		}
		if(name2index.count(dest)==false){
			name2index[dest]=index;
			index2name[index]=src;
			index++;
		}else{
			int tmp=name2index[dest];
		}
	}

	map<string, int> name2head;
	
	for(auto it:time_table){
		cout<<it<<" "<<endl;
	}
	cout<<endl;
	for(auto it:name2head){
		cout<<it.first<<" "<<it.second<<endl;
	}

}
