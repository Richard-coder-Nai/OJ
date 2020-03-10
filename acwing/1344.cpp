#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int n;
vector<vector<char>> mat;
vector<vector<char>> res;
vector<vector<char>> tmp;

void mirror(){
	for(int i=0; i<n; i++){
		reverse(tmp[i].begin(), tmp[i].end());
	}
}

void rotate90(){
	for(int i=0; i<n; i++){
		for(int j=0; j<i; j++){
			swap(tmp[i][j], tmp[j][i]);
		}
	}
	mirror();
}


string str;
int main(void){
	cin>>n;
	mat.assign(n, vector<char>(n, 0));
	res.assign(n, vector<char>(n, 0));

	// input
	for(int i=0; i<n; i++){
		cin>>str;
		for(int j=0; j<n; j++){
			mat[i][j] = str[j];
		}
	}
	for(int i=0; i<n; i++){
		cin>>str;
		for(int j=0; j<n; j++){
			res[i][j] = str[j];
		}
	}

	// judge
	tmp = mat;
	rotate90();
	if(tmp==res) {
		cout<<1<<endl;
		return 0;
	}
	rotate90();
	if(tmp==res) {
		cout<<2<<endl;
		return 0;
	}
	rotate90();
	if(tmp==res) {
		cout<<3<<endl;
		return 0;
	}

	tmp = mat;
	mirror();
	if(tmp==res) {
		cout<<4<<endl;
		return 0;
	}

	rotate90();
	if(tmp==res) {
		cout<<5<<endl;
		return 0;
	}
	rotate90();
	if(tmp==res) {
		cout<<5<<endl;
		return 0;
	}
	rotate90();
	if(tmp==res) {
		cout<<5<<endl;
		return 0;
	}

	if(res==mat){
		cout<<6<<endl;
		return 0;
	}

	cout<<7<<endl;
	return 0;
}
