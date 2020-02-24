#include<iostream>
#include<list>

using namespace std;

list<int> table;
char opt;

int main(void){
	int M;
	cin>>M;
	for(int i=0; i<M; i++){
		cin>>opt;
		if(opt=='H'){
			int n;
			cin>>n;
			table.push_front(n);
		}

		if(opt=='D'){
			int k;
			if(k==0) 
				table.erase(table.begin());
			else
				table.erase(table.begin()+k+1, table.end());
		}

		if(opt=='I'){
			int k,x;
			cin>>k>>x;
			table.insert(table.begin()+k, x);
		}
	}

	for(auto it:table){
		cout<<it<<" ";
	}
	cout<<endl;
}
