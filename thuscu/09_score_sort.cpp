/*************************************************************************
	> File Name: 09_score_sort.cpp
	> Author: zhangyang
	> Mail: zyziszy@foxmail.com
	> Created Time: Fri 10 Jan 2020 08:31:44 PM CST
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<set>

using namespace std;

void print_fun(vector<set<int>> table){
	for(int i=0; i<101; i++){
		if(table[i].size()){
			for(auto it: table[i]){
				cout<<it<<" "<<i<<endl;
			}
		}
	}
}


int main(void){
	int n;
	while(cin>>n){
		vector<set<int>> table(101); 
		for(int i=0; i<n; i++){
			int id;
			int score;
			cin>>id>>score;

			table[score].insert(id);
		}
		print_fun(table);
	}    
}
