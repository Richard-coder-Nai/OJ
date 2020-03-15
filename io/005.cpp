/*************************************************************************
	> File Name: 005.cpp
	> Author: Yang Zhang 
	> Mail: zyziszy@foxmail.com 
	> Created Time: Fri Mar 13 08:46:29 2020
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;


static bool cmp(string s1, string s2){
	int i = 0;
	while(s1[i]==s2[i]) i++;

	return s1[i]<s2[i];
}

int n;
string str;
int main(void){
	while(cin>>n){
		vector<string> table;
		for(int i=0; i<n; i++){
			cin>>str;
			table.push_back(str);
		}
		sort(table.begin(), table.end(), cmp);
		for(auto it: table) cout<<it<<" ";
		cout<<endl;
	}
}
