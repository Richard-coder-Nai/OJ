#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, m;
struct PATH{
	int x, y;
	int t;
};
PATH path[100005];

static bool cmp(PATH a, PATH b){
	return a.t < b.t;
}

int father[1005];
int cnt[1005];

void init(){
	for(int i=0; i<=n; i++){
		father[i] = i;
		cnt[i] = 1;
	}
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
	init();
	for(int i=0; i<m; i++){
		int x, y, z;
		cin>>x>>y>>z;
		path[i] = {x, y, z};
	}
	if(n-1>m){
		cout<<-1<<endl;
		return 0;
	}
	sort(path, path+m, cmp);

	for(int i=0; i<m; i++){
		int x = path[i].x;
		int y = path[i].y;
		int fx = find_father(x);
		int fy = find_father(y);
		if(fx!=fy){
			father[fx] = fy;
			cnt[fy] += cnt[fx];
			if(cnt[fy]==n){
				cout<<path[i].t<<endl;
				return 0;
			}
		}
	}
	cout<<-1<<endl;
	return 0;
}
