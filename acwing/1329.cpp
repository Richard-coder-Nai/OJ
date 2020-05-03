#include <iostream>
#include <string>

using namespace std;

string dirs[1005];
int father[1005];

int counter(int x) {
	if(father[x]==0) return dirs[x].size()+1;
	return dirs[x].size()+1+counter(father[x]);
}

int main(void) {
	int n;
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>father[i];
		cin>>dirs[i];
	}
	int res = 0;
	for(int i=1; i<=n; i++) res += counter(i);

	cout<<res<<endl;
}

