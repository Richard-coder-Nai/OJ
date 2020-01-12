#include<iostream>
#include<vector>
#include<string>
#include<sstream>

using namespace std;


int main(void){
	vector<int> table;
	string str;
	getline(cin, str);
	stringstream stream;
	stream<<str;

	int n;
	while(stream>>n){
		table.push_back(n);
	}

	int first_num;
	for(int i=1; i<table.size(); i++){
		if(table[i]){
			table[i]--;
			first_num = i;
			break;
		}
	}


	cout<<first_num;
	for(int i=0; i<table.size(); i++){
		for(int j=0; j<table[i]; j++){
			cout<<i;
		}
	}
	
}
