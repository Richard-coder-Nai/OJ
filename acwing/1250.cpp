#include <iostream>

using namespace std;

int father[40005];
int n, m;

int find_father(int x, int y) {
	int pos = x*n + y;
	int a = pos;
	while(father[pos]!=pos) {
		pos = father[pos];
	}
	while(a!=pos) {
		int z = father[a];
		father[a] = pos;
		a = z;
	}
	return pos;
}

int main(void) {
	cin>>n>>m;
	for(int i=0;i<=n*n; i++) father[i] = i;

	for(int i=1; i<=m; i++) {
		int x1, y1, x2, y2;
		char opt;
		cin>>x1>>y1>>opt;
		x1--;
		y1--;
		x2 = x1;
		y2 = y1;
		if(opt=='D') x2++;
		if(opt=='U') x2--;
		if(opt=='R') y2++;
		if(opt=='L') y2--;

		int f1 = find_father(x1, y1);
		int f2 = find_father(x2, y2);
		if(f1==f2) {
			cout<<i<<endl;
			return 0;
		}
		father[f1] = f2;
	}

	cout<<"draw"<<endl;
}
