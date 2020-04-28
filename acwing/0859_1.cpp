#include <iostream>
#include <algorithm>

using namespace std;

int n, m;

struct Node{
	int x, y, w;
};

bool cmp(Node n1, Node n2) {
	return n1.w < n2.w;
}

Node node[200005];
int father[100005];

int find_father(int x) {
	int a = x;
	while(father[x]!=x) x = father[x];
	while(a!=x) {
		int z = father[a];
		father[a] = x;
		z = a;
	}
	return x;
}

int main(void) {
	cin>>n>>m;
	for(int i=0; i<=n; i++) father[i] = i;
	for(int i=0; i<m; i++) {
		int x, y, w;
		cin>>x>>y>>w;
		node[i] = {x, y, w};
	}

	if(n-1>m) {
		cout<<"impossible"<<endl;
		return 0;
	}

	sort(node, node+m, cmp);

	int cnt = 0;
	int res = 0;
	for(int i=0; i<m; i++) {
		int fx = find_father(node[i].x);
		int fy = find_father(node[i].y);
		if(fx!=fy) {
			father[fx] = fy;
			res += node[i].w;
			cnt++;
			if(cnt==n-1) {
				cout<<res<<endl;
				return 0;
			}
		}
	}
	cout<<"impossible"<<endl;
}
