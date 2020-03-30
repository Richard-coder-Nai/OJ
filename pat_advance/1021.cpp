#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n;
vector<vector<int>> adj;
vector<bool> used;

int father[100010];


int find_father(int x){
	int a = x;
	while(father[x]!=x) x= father[x];
	while(a!=x){
		int z = father[a];
		father[a] = x;
		a = z;
	}
	return x;
}


int main(void){
	cin>>n;
	adj.assign(n+1, vector<int>());
	for(int i=0; i<=n; i++){
		father[i] = i;
	}

	int cnt = 0;
	for(int i=1; i<n; i++){
		int x, y;
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
		int fx = find_father(x);
		int fy = find_father(y);
		if(fx!=fy){
			cnt++;
			father[fx] = fy;
		}
	}
	if(cnt!=n-1) {cout<<"Error: "<<n-cnt<<" components"<<endl; return 0;}

	vector<int> height;
	int res = 0;
	for(int i=1; i<=n; i++){
		used.assign(n+1, false);
		used[i] = true;
		queue<int> q;
		q.push(i);
		int h = 0;
		while(q.size()){
			h++;
			int size = q.size();
			while(size--){
				int front = q.front();
				q.pop();
				for(auto it:adj[front]){
					if(used[it]==false){
						q.push(it);
						used[it] = true;
					}
				}
			}
		}
		res = max(h, res);
		height.push_back(h);
	}
	for(int i=0; i<height.size(); i++){
		if(height[i]==res){
			cout<<i+1<<endl;
		}
	}
}
