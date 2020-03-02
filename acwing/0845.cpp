#include<iostream>
#include<string>
#include<queue>
#include<unordered_map>

using namespace std;

string dest;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

unordered_map<string, int> dist;

int main(void){
	char c;
	for(int i=0; i<9; i++){
		cin>>c;
		dest += c;
	}

	string start = "12345678x";
	queue<string> q;
	q.push(start);
	dist[start] = 0;

	while(q.size()){
		auto front = q.front();
		q.pop();
		int distance = dist[front];
		if(front==dest){
			cout<<distance<<endl;
			return 0;
		}
		int k = front.find('x');
		int x = k/3;
		int y = k%3;
		for(int i=0; i<4; i++){
			int nx = x+dx[i];
			int ny = y+dy[i];
			int nk = nx*3+ny;
			if(nx>=0 && ny>=0 && nx<3 && ny<3){
				string ns = front;
				ns[k] = ns[nk];
				ns[nk] = 'x';
				if(dist.count(ns)==false){
					dist[ns] = distance+1;
					q.push(ns);
				}
			}
		}
	}
	cout<<-1<<endl;
}
