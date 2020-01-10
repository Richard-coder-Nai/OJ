/*************************************************************************
	> File Name: 02_score_sort.cpp
	> Author: zhangyang
	> Mail: zyziszy@foxmail.com
	> Created Time: Fri 10 Jan 2020 08:31:44 PM CST
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<list>

using namespace std;

void print_fun(int mode, vector<list<string>> table){
	if(mode){
		for(int i=0; i<101; i++){
			if(table[i].size()){
				for(auto it: table[i]){
					cout<<it<<" "<<i<<endl;
				}
			}
		}
	}else{
		for(int i=100; i>=0; i--){
			if(table[i].size()){
				for(auto it: table[i]){
					cout<<it<<" "<<i<<endl;
				}
			}
		}
	}
}


int main(void){
	int n, mode;
	while(cin>>n>>mode){
		vector<list<string>> table(101); 
		for(int i=0; i<n; i++){
			string name;
			int score;
			cin>>name>>score;

			table[score].push_back(name);
		}
		print_fun(mode, table);
	}    
}
