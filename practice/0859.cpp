#include<iostream>
#include<algorithm>

using namespace std;

int n, m;
int father[100005];

struct NODE{
	int x, y;
	int val;
};

NODE node[200005];

static bool cmp(NODE n1, NODE n2){
	return n1.val<n2.val;
}

int find_father(int x){
	int a = x;
	while(x!=father[x]) x = father[x];
	while(a!=x){
		int z = father[a];
		father[a] = x;
		a = z;
	}
	return x;
}

int main(void){
	cin>>n>>m;
	for(int i=0; i<=n; i++) father[i] = i;
	for(int i=0; i<m; i++){
		int x, y, z;
		cin>>x>>y>>z;
		node[i] = {x, y, z};
	}
	if(n-1>m){
		cout<<"impossible"<<endl;
		return 0;
	}
	sort(node, node+m, cmp);

	int cnt = 0;
	int res = 0;
	for(int i=0; i<m; i++){
		int fx = find_father(node[i].x);
		int fy = find_father(node[i].y);
		if(fx!=fy){
			cnt++;
			res += node[i].val;
			father[fx] = fy;
		}
		if(cnt==n-1) break;
	}
	if(cnt!=n-1){
		cout<<"impossible"<<endl;
	}else{
		cout<<res<<endl;
	}
}

