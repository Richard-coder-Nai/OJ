#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int t, n, w;

struct NODE{
	int x, y, w;
};

int father[505];
static bool cmp(NODE n1, NODE n2){
	return n1.w < n2.w;
}

void init(){
	for(int i=0; i<n; i++) father[i] = i;
}

int find_father(int x){
	while(father[x]!=x) x = father[x];
	return x;
}

int main(void){
	cin>>t;
	while(t--){
		cin>>n;
		vector<NODE> node;
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				cin>>w;
				if(w) node.push_back({i, j, w});
			}
		}
		init();
		sort(node.begin(), node.end(), cmp);
		int cnt = 0;
		int res = 0;
		
		int size = node.size();
		for(int i=0; i<size; i++){
			int fx = find_father(node[i].x);
			int fy = find_father(node[i].y);
			if(fx!=fy){
				cnt++;
				res += node[i].w;
				father[fx] = fy;
				if(cnt==n-1) break;
			}
		}
		cout<<res<<endl;
	}
}
