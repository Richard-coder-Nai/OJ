#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n;
vector<vector<int>> matrix;
int opt, k;

void transpose(){
	for(int i=0; i<n; i++){
		for(int j=0; j<=i; j++){
			swap(matrix[i][j], matrix[j][i]);
		}
	}
}

void row_shift(int k){
	k = k%n;
	if(k==0) return;
	reverse(matrix.begin(), matrix.end());
	reverse(matrix.begin(), matrix.begin()+k);
	reverse(matrix.begin()+k, matrix.end());
}

void col_shift(int k){
	k = k%n;
	if(k==0) return;
	transpose();
	row_shift(k);
	transpose();
}

int main(void){
	cin>>n;
	for(int i=0; i<n; i++){
		vector<int> tmp;
		for(int j=0; j<n; j++){
			int x;
			cin>>x;
			tmp.push_back(x);
		}
		matrix.push_back(tmp);
	}
	int q;
	cin>>q;
	while(q--){
		cin>>opt;
		if(opt==1) transpose();
		if(opt==2){
			cin>>k;
			row_shift(k);
		}
		if(opt==3){
			cin>>k;
			col_shift(k);
		}
	}

	for(auto it:matrix){
		for(auto v:it){
			cout<<v<<" ";
		}
		cout<<endl;
	}
}
