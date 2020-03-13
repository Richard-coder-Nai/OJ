#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int h[1005];
int up[1005];
int down[1005];
int f[1005];

int n;

int main(void){
	cin>>n;
	for(int i=1; i<=n; i++){
		cin>>h[i];
	}

	for(int i=1; i<=n; i++){
		for(int j=0; j<i; j++){
			if(h[i]>h[j]){
				up[i] = max(up[i], up[j]+1);
			}
		}
	}
	for(int i=n; i>=1; i--){
		for(int j=n+1; i<j; j--){
			if(h[i]>h[j]){
				down[i] = max(down[i], down[j]+1);
			}
		}
	}
	for(int i=1; i<=n; i++){
		f[i] = up[i]+down[i];
	}
	cout<<*max_element(f, f+n+1)-1<<endl;
}
