#include<iostream>
#include<algorithm>

using namespace std;

struct Node{
	int x, y, z;
}node[1005];

int father[105];

static bool cmp(Node n1, Node n2){
	return n1.z<n2.z;
}

int find_father(int x){
	int a = x;
	while(father[x]!=x){
		x = father[x];
	}
	while(x!=a){
		int z = father[a];
		father[a] = x;
		a = z;
	}
	return x;
}

int n, k;
int main(void) {
	cin>>n>>k;
	for(int i=0; i<=n; i++) father[i] = i;

	long long sum = 0;
	for(int i=0; i<k; i++) {
		int x, y, z;
		cin>>x>>y>>z;
		node[i] = {x, y, z};
		sum += z;
	}
	sort(node, node+k, cmp);

	int cnt = 0;
	long long min_path = 0;
	for(int i=0; i<k; i++){
		int fx = find_father(node[i].x);
		int fy = find_father(node[i].y);
		if(fy!=fx){
			cnt++;
			father[fx] = fy;
			min_path += node[i].z;
		}
		if(cnt==n-1) break;
	}
	cout<<sum-min_path<<endl;
}
