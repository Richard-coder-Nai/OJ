#include<iostream>

using namespace std;

int n;
int g[35][35];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main(void){
	cin>>n;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin>>g[i][j];
		}
	}
	for(int i=1; i<n-1; i++){
		for(int j=1; j<n-1; j++){
			if(g[i][j]==1){
				bool flag = true;
				for(int k=0; k<4; k++){
					int nx = i+dx[k];
					int ny = j+dy[k];
					if(g[nx][ny]==0) {
						flag==false;
						break;
					}
				}
				if(flag) g[i][j] = 2;
			}
		}
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout<<g[i][j]<<" ";
		}
		cout<<endl;
	}

}
