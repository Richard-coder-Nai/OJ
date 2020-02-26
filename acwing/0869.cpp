#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(void){
	int n;
	cin>>n;

	int k;
	while(n--){
		cin>>k;
		vector<int> table;
		for(int i=1; i*i<=k; i++){
			if(k%i==0){
				table.push_back(i);
				if(i!=k/i)
					table.push_back(k/i);
			}
		}
		sort(table.begin(), table.end());
		for(auto it:table){
			cout<<it<<" ";
		}
		cout<<endl;
	}
}
