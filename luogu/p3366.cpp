#include<iostream>
#include<algorithm>

using namespace std;

int n, m;
int father[5005];
struct NODE{
	int x, y;
	int w;
};

NODE node[200005];

static bool cmp(NODE n1, NODE n2){
	return n1.w < n2.w;
}

int find_father(int x){
	int a = x;
	while(x!=father[x]) x = father[x];
	while(x!=a){
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
		int x, y, w;
		scanf("%d %d %d", &x, &y, &w);
		node[i] = {x, y, w};
	}
	sort(node, node+m, cmp);

	int res = 0;
	int cnt =0;
	for(int i=0; i<m; i++){
		int x = node[i].x;
		int y = node[i].y;
		int w = node[i].w;
		int fx = find_father(x);
		int fy = find_father(y);
		if(fx!=fy){
			cnt++;
			res += w;
			father[fx] = fy;
			if(cnt==n-1){
				cout<<res<<endl;
				return 0;
			}
		}
	}
	cout<<"orz"<<endl;
	return 0;
}
