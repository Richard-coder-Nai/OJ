#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std;

char opt;
int x, y;
int n, m;

int nums[30005] = {0};

int main(void){
	while(scanf("%d %d", &n, &m)!=EOF){

		for(int i=1; i<=n; i++){
			cin>>nums[i];
		}
		for(int i=0; i<m; i++){
			cin>>opt>>x>>y;
			int l = min(x, y);
			int r = max(x, y);
			if(opt=='U'){
				nums[x] = y;
			}else{
				int ans = -1;
				for(int i=l; i<=r; i++){
					ans = max(ans, nums[i]);
				}
				cout<<ans<<endl;
			}
		}
	}
}
