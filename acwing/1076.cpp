#include<iostream>
#include<queue>

using namespace std;

int g[105][105];
int n;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int tmp;

struct pos{
	int x;
	int y;
};
pos Node;
queue<pos> q;

int main(void){
	cin>>n;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin>>tmp;
			if(tmp!=0)
				g[i][j] = -1;
		}
	}

	Node.x = n-1;
	Node.y = n-1;
	q.push(Node);

	int step = 1;
	while(q.size()){
		int size = q.size();
		for(int i=0; i<size; i++){
			auto front = q.front();
			q.pop();
			int x = front.x;
			int y = front.y;
			g[x][y] = step;
			
			for(int i=0; i<4; i++){
				int nx = x+dx[i];
				int ny = y+dy[i];
				if(nx>=0 && nx<n && ny>=0 && ny<n && g[nx][ny]==0){
					Node.x = nx;
					Node.y = ny;
					q.push(Node);
				}
			}
		}
		step++;
	}

	Node.x = 0;
	Node.y = 0;
	q.push(Node);

	while(q.size()){
		auto front = q.front();
		q.pop();
		int x = front.x;
		int y = front.y;
		cout<<x<<" "<<y<<endl;
		if(x==n-1 && y==n-1) break;

		step = g[x][y];
		for(int i=0; i<4; i++){
			int nx = x+dx[i];
			int ny = y+dy[i];
			if(nx>=0 && nx<n && ny>=0 && ny<n && g[nx][ny]+1==step){
				Node.x = nx;
				Node.y = ny;
				q.push(Node);
				break;
			}
		}
	}
}
