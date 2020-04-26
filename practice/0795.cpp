#include <iostream>

using namespace std;

const int N = 100005;
int nums[N];
int sum[N];

int main(void) {
	int n, m;
	cin>>n>>m;

	for(int i=1; i<=n; i++) {
		cin>>nums[i];
		sum[i] = nums[i]+sum[i-1];
	}

	while(m--) {
		int x, y;
		cin>>x>>y;
		cout<<sum[y]-sum[x-1]<<endl;
	}
}
