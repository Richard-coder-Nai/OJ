#include<iostream>
#include<vector>

using namespace std;

int g[105][105];
int n;

int prim(){
	vector<int> dist(n, 1000005);
	vector<bool> used(n, false);
	dist[0] = 0;
	int res = 0;
	for(int i=0; i<n; i++){
		int t = -1;
		for(int j=0; j<n; j++){
			if(used[j]==false && (t==-1||dist[j]<dist[t])){
				t = j;
			}
		}
		used[t] = true;
		res += dist[t];
		for(int j=0; j<n; j++){
			if(used[j]==false && t!=j){
				dist[j] = min(dist[j], g[t][j]);
			}
		}
	}
	return res;
}

int main(void){
	cin>>n;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin>>g[i][j];
		}
	}
	cout<<prim()<<endl;

}
