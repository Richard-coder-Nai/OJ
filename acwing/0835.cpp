#include<iostream>
#include<map>
#include<string>

using namespace std;

int main(void){
	int n;
	cin>>n;

	map<string, int> table;

	for(int i=0; i<n; i++){
		char opt;
		string str;
		cin>>opt>>str;
		if(opt=='I'){
			if(table.count(str)){
				table[str]++;
			}else{
				table[str]=1;
			}
		}

		if(opt=='Q'){
			if(table.count(str)){
				cout<<table[str]<<endl;
			}else{
				cout<<0<<endl;
			}
		}
	}
}
