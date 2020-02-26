#include<iostream>

using namespace std;

const int INF = 0x3f3f3f3f;

int d[210][210];
int n, m, k;

void floyd(){
	for(int k=1; k<=n; k++){
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
			}
		}
	}
}

int main(void){
	cin>>n>>m>>k;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if(i==j) d[i][j] = 0;
			else{
				d[i][j] = INF;
			}
		}
	}

	for(int i=1; i<=m; i++){
		int x, y, z;
		cin>>x>>y>>z;
		d[x][y] = min(z, d[x][y]);
	}

	floyd();

	for(int i=0; i<k; i++){
		int x, y;
		cin>>x>>y;
	
		if(d[x][y]>INF/2){
			cout<<"impossible"<<endl;
		}else{
			cout<<d[x][y]<<endl;
		}
	}
}
