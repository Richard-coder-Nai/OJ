#include<iostream>
#include<string>
#include<map>
#include<vector>

using namespace std;

map<int, string> table({{0, "zero"}, 
		{1, "one"},
		{2, "two"},
		{3, "three"},
		{4, "four"},
		{5, "five"},
		{6, "six"},
		{7, "seven"},
		{8, "eight"},
		{9, "nine"}
		});
int main(void){

	string str;
	cin>>str;
	int n = 0;
	for(auto it:str){
		n += (it-'0');
	}
	if(n==0){
		cout<<table[n]<<endl;
		return 0;
	}
	vector<int> tmp;
	while(n){
		tmp.push_back(n%10);
		n = n/10;
	}

	for(auto it=tmp.rbegin(); it!=tmp.rend(); it++){
		cout<<table[*it]<<" ";
	}
	cout<<endl;
	return 0;
}
