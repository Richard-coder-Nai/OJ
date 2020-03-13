#include<iostream>

using namespace std;

int sum[1005][1005];
int nums[1005][1005];

int main(void){
	int n, m, q;
	cin>>n>>m>>q;

	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			cin>>nums[i][j];
			sum[i][j] = nums[i][j]+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
		}
	}

	for(int i=1; i<=q; i++){
		int x1, y1, x2, y2;
		cin>>x1>>y1>>x2>>y2;
		cout<<sum[x2][y2]+sum[x1-1][y1-1]-sum[x2][y1-1]-sum[x1-1][y2]<<endl;
	}
}
