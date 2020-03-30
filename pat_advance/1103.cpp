#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;

int n, k, p;

vector<int> path;
vector<int> table;
vector<vector<int>> res;

static bool cmp(vector<int> v1, vector<int> v2){
	int sum1 = 0, sum2 = 0;
	for(int tmp:v1) sum1 += tmp;
	for(int tmp:v2) sum2 += tmp;
	return sum1 < sum2;
}

void dfs(int n){
	if(n<0||path.size()>k) return;
	if(path.size()==k && n==0){
		res.push_back(path);
		return;
	}
	for(int i=0; i<table.size(); i++){
		path.push_back(table[i]);
		dfs(n-pow(table[i], p));
		path.pop_back();
	}
	return;
}

int main(void){
	cin>>n>>k>>p;
	int tmp = 1;
	while(pow(tmp, p)<=n){
		table.push_back(tmp);
		tmp++;
	}

	reverse(table.begin(), table.end());
	for(auto it:table) cout<<it<<" ";
	cout<<endl;


	dfs(n);
	if(res.size()==0){
		cout<<"Impossible"<<endl;
		return 0;
	}

	sort(res.begin(), res.end(), cmp);
	bool flag = false;
	auto back = res.back();
	sort(back.begin(), back.end());
	reverse(back.begin(), back.end());
	for(auto it:back){
		if(flag) cout<<" + ";
		else cout<<n<<" = ";
		cout<<it<<"^"<<p;
		flag = true;
	}
}
