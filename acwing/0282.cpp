#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int main(void){
	int n;
	cin>>n;

	vector<int> table(n, 0);
	for(int i=0; i<n; i++){
		cin>>table[i];
	}

	if(n==1){
		cout<<0<<endl;
		return 0;
	}


	int counter = 0;
	while(table.size()>1){
		int Min = table[0]+table[1];
		int idx = 0;
		int d = abs(table[1]-table[0]);
		for(int i=0; i<table.size()-1; i++){
			int tmp = table[i]+table[i+1];
			if(Min>tmp){
				idx = i;
				Min = table[i]+table[i+1];
			}
			if(Min==tmp){
				if(abs(table[i]-table[i-1])>d){
					idx = i;
				}
			}
		}
		counter+=Min;
		table[idx] = Min;
		table.erase(table.begin()+idx+1);
	}
	cout<<counter<<endl;
}

