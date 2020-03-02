#include<iostream>
#include<vector>

using namespace std;

typedef pair<int, int> PII;

int x, y;

vector<PII> step;
int g[16][16];
int n;

int dx[4] = {1, 0, 1, 1};
int dy[4] = {0, 1, 1, -1};


bool ifwin(int x, int y, int k){
	g[x][y] = k;
	int size = -1;
	for(int i=0; i<4; i++){
		int res = -1;
		int move = 0;
		while(x+dx[i]*move>0 && x+dx[i]*move<=15 && y+dy[i]*move>0 && y+dy[i]*move<=15 && g[x+dx[i]*move][y+dy[i]*move]==k){
			move++;
		}
		res += move;
		move = 0;

		while(x-dx[i]*move>0 && x-dx[i]*move<=15 && y-dy[i]*move>0 && y-dy[i]*move<=15 && g[x-dx[i]*move][y-dy[i]*move]==k){
			move++;
		}
		res += move;
		size = max(size, res);
	}
	if(size>=5) return true;
	return false;
}


int main(void){
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>x>>y;
		step.push_back(make_pair(x, y));
	}

	for(int i=0; i<n; i++){
		int x = step[i].first;
		int y = step[i].second;
		if(i%2==0){
			if(ifwin(x, y, 1)){
				cout<<"A "<<i+1<<endl;
				return 0;
			}
		}else{
			if(ifwin(x, y, 2)){
				cout<<"B "<<i+1<<endl;
				return 0;
			}
		}
	}

	cout<<"Tie"<<endl;
	return 0;
}
