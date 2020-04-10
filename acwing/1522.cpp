#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

static bool cmp(string str_x, string str_y){
	if(str_x==str_y) return true;
	int x_size = str_x.size();
	int y_size = str_y.size();

	if(x_size==y_size){
		int idx = 0;
		while(str_x[idx]==str_y[idx]){
			idx++;
		}
		return str_x[idx]<str_y[idx];
	}

	int n = min(y_size, x_size);
	for(int i=0; i<n; i++){
		if(str_x[i]!=str_y[i]){
			return str_x[i]<str_y[i];
		}
	}

	if(x_size%y_size==0){
		string tmp = "";
		int cnt = x_size/y_size;
		while(cnt--){
			tmp += str_y;
		}
		if(tmp==str_x) return true;
	}
	if(y_size%x_size==0){
		string tmp = "";
		int cnt = y_size/x_size;
		while(cnt--){
			tmp += str_x;
		}
		if(tmp==str_y) return true;
	}
	int i = 0;
	int j = 0;
	int pause = -1;
	while(str_x[i]==str_y[i]){
		i = (i+1)%x_size;
		j = (j+1)%y_size;
		if(i==0 && j==0){
			pause++;
			if(pause==1) break;
		}
	}
	return str_x[i]<str_y[j];
}


int n;
vector<string> table;
int main(void){
	cin>>n;
	table.assign(n, "");
	for(int i=0; i<n; i++){
		string str;
		cin>>str;
		table[i] = str;
	}
	sort(table.begin(), table.end(), cmp);
	cout<<atoi(table[0].c_str());
	for(int i=1; i<table.size(); i++){
		cout<<table[i];
	}
	cout<<endl;
}
