#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n;
vector<int> a, b, c;
int main(void){
	scanf("%d", &n);
	a.assign(n, 0);
	b.assign(n, 0);
	c.assign(n, 0);
	for(int i=0; i<n; i++) scanf("%d", &a[i]);
	for(int i=0; i<n; i++) scanf("%d", &b[i]);
	for(int i=0; i<n; i++) scanf("%d", &c[i]);

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	sort(c.begin(), c.end());

	long long  res = 0;
	for(int i=0; i<n; i++){
		int l = distance(a.begin(), lower_bound(a.begin(), a.end(), b[i]));
		int r = distance(c.begin(), upper_bound(c.begin(), c.end(), b[i]));
		r = n-r;
		res += r*l;
	}
	cout<<res<<endl;
}
