#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <unordered_map>

using namespace std;

string target = "12345678x";
string str;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
unordered_map<string, int> table;

int main(void) {
	char c;
	for(int i=0; i<9; i++) {
		cin>>c;
		str += c;
	}

	int step = 0;
	queue<string> q;

	q.push(target);
	table[target] = 0;
	while(q.size()) {
		int size = q.size();
		for(int i=0; i<size; i++) {
			auto front = q.front();
			q.pop();
			if(str==front) {
				cout<<step<<endl;
				return 0;
			}
			int k = front.find('x');
			int x = k/3;
			int y = k%3;
			for(int i=0; i<4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				
				if(nx>=0 && ny>=0 && nx<3 && ny<3) {
					string tmp = front;
					swap(tmp[k], tmp[3*nx+ny]);
					if(table.count(tmp)==false) {
						table[tmp] = step;
						q.push(tmp);
					}
				}
			}
		}
		step++;
	}
	cout<<-1<<endl;
}

