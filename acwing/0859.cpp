#include<iostream>
#include<algorithm>

using namespace std;

int n, m;
struct Edge{
	int x, y;
	int w;
};
Edge edge[200005];
int father[200005];

static bool cmp(Edge e1, Edge e2){
	return e1.w < e2.w;
}

int find_father(int x){
	int a = x;
	while(x!=father[x]) x = father[x];
	while(x!=a){
		int z = father[a];
		father[a] = x;
		a = x;
	}
	return x;
}


int x, y, z;
int main(void){
	cin>>n>>m;
	
	for(int i=0; i<m; i++){
		scanf("%d%d%d", &x, &y, &z);
		edge[i] = {x, y, z};
	}

	if(n-1>m){
		cout<<"impossible"<<endl;
		return 0;
	}

	sort(edge, edge+m, cmp);
	for(int i=1; i<=n; i++) father[i] = i;
	int cnt = 0;
	int res = 0;
	for(int i=0; i<m; i++){
		if(cnt==n-1) break;
		int x = edge[i].x;
		int y = edge[i].y;
		int w = edge[i].w;

		int fx = find_father(x);
		int fy = find_father(y);
		if(fx!=fy){
			cnt ++;
			res += w;
			father[fx] = fy;
		}
	}
	if(cnt!=n-1) cout<<"impossible"<<endl;
	else cout<<res<<endl;
}

