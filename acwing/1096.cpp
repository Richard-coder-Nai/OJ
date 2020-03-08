#include<iostream>
#include<vector>
#include<string>
#include<queue>

using namespace std;

int l, r, c;

int map[105][105][105];
int dx[6] = {1, 0, 0, -1, 0, 0};
int dy[6] = {0, 0, 1, 0, -1, 0};
int dz[6] = {0, 1, 0, 0, 0, -1};

int main(void){
	while(true){
		cin>>l>>r>>c;
		if(l==r && r==c && c==0) break;

		vector<int> src(3, 0);
		vector<int> dest(3, 0);

		string tmp;
		for(int i=0; i<l; i++){
			for(int k=0; k<r; k++){
				cin>>tmp;
				for(int j=0; j<c; j++){
					map[i][k][j] = 0;

					if(tmp[j]=='#'){
						map[i][k][j] = -1;
					}
					if(tmp[j]=='S'){
						src[0] = i;
						src[1] = k;
						src[2] = j;
						map[i][k][j] = -1;
					}
					if(tmp[j]=='E'){
						dest[0] = i;
						dest[1] = k;
						dest[2] = j;
					}
				}
			}
		}

		queue<vector<int>> q;
		q.push(src);

		/*
		for(int i=0; i<l; i++){
			for(int k=0; k<r; k++){
				for(int j=0; j<c; j++){
					cout<<map[i][k][j]<<" ";
				}
				cout<<endl;
			}
			cout<<endl;
		}
		*/
	

		int timer = 0;
		bool flag = false;
		while(!q.empty()){
			int size = q.size();
			for(int i=0; i<size; i++){
				auto front = q.front();
				q.pop();
				if(front==dest){
					flag = true;
					printf("Escaped in %d minute(s).\n", timer);
					break;
				}
				int x = front[0];
				int y = front[1];
				int z = front[2];
				for(int j=0; j<6; j++){
					int nx = x + dx[j];
					int ny = y + dy[j];
					int nz = z + dz[j];
					if(nx>=0 && ny>=0 && nz>=0 && nx<l && ny<r && nz<c && map[nx][ny][nz]==0){
						vector<int> pos(3, 0);
						map[nx][ny][nz] = -1;
						pos[0] = nx;
						pos[1] = ny;
						pos[2] = nz;
						q.push(pos);
					}
				}
			}
			timer++;
		}

		if(flag==false)
			cout<<"Trapped!"<<endl;
	}
}
