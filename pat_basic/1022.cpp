#include<iostream>
#include<vector>

using namespace std;


int main(void){
	int	A, B, d;
	cin>>A>>B>>d;

	int sum=A+B;
	if(sum==0){
		cout<<0<<endl;
		return 0;
	}

	vector<int> table;

	while(sum){
		int re=sum%d;
		table.push_back(re);
		sum=sum/d;
	}

	for(auto it=table.rbegin(); it!=table.rend(); it++){
		cout<<*it;
	}
	cout<<endl;
}
