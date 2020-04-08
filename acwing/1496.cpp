#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, b;

int main(void){
	cin>>n>>b;
	if(n==0){
		cout<<"Yes"<<endl;
		cout<<0<<endl;
		return 0;
	}
	vector<int> table;
	while(n){
		table.push_back(n%b);
		n = n/b;
	}
	auto res = table;
	reverse(res.begin(), res.end());
	if(res==table) cout<<"Yes\n";
	else cout<<"No"<<endl;
	for(auto it:res) cout<<it<<" ";
	cout<<endl;
}
