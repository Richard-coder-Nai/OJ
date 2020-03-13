#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int>> table;

static bool cmp(vector<int> n1, vector<int> n2){
	if(n1[0]==n2[0]){
		return n1[1]<n2[1];
	}
	return n1[0]<n2[0];
}

int main(void){
	int n;
	cin>>n;

	table.assign(n, vector<int>(2, 0));
	for(int i=0; i<n; i++){
		cin>>table[i][0]>>table[i][1];
	}

	sort(table.begin(), table.end(), cmp);


	/*
	vector<vector<int>> res(table.begin(), table.begin()+1);
	for(int i=1; i<n; i++){
		if(res[res.size()-1][1]>=table[i][0]){
			if(table[i][1]>res[res.size()-1][1]){
				res[res.size()-1][1] = table[i][1];
			}
		}else{
			res.push_back(table[i]);
		}
	}
	cout<<res.size()<<endl;
	*/

	int res = n;
	int start = table[0][0];
	int end = table[0][1];
	for(int i=1; i<n; i++){
		if(end>=table[i][0]){
			end = max(table[i][1], end);
			res--;
		}else{
			start = table[i][0];
			end = table[i][1];
		}
	}
	cout<<res<<endl;
}

