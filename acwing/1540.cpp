#include<iostream>
#include<unordered_map>

using namespace std;

int n, m;
unoredred_map<long long, int> table;

int main(void){
	cin>>n>>m;
	n = n*m
	for(int i=0; i<n; i++){
		long long x;
		cin>>x;
		table[x]++;
	}
	for(auto it:table){
		if(it.second>n/2){
			cout<<it.first<<endl;
		}
	}
}
