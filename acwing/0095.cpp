// so slow

#include <iostream>
#include <queue>
#include <bitset>
#include <string>

using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
string str;

bitset<25> turn(int x, int y, bitset<25> map) {
	int pos = 5*x + y;
	map[pos] = !map[pos];
	for(int i=0; i<4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(nx>=0 && ny>=0 && nx<5 && ny<5) {
			pos = 5*nx + ny;
			map[pos] = !map[pos];
		}
	}
	return map;
}

int main(void) {
	bitset<25> target;

	/*
	target = turn(1, 1, target);
	for(int i=0; i<5; i++) {
		for(int j=0; j<5; j++) {
			cout<<target[i*5+j];
		}
		cout<<endl;
	}
	*/

	for(int i=0; i<5; i++) {
		cin>>str;
		for(int j=0; j<5; j++) {
			if(str[j]=='1'){
				target[i*5+j] = true;
			}
		}
	}
	/*
	cout<<"hi"<<endl;
	for(int i=0; i<5; i++) {
		for(int j=0; j<5; j++) {
			cout<<target[i*5+j];
		}
		cout<<endl;
	}
	*/


	bitset<25> table;
	table.set();

	queue<bitset<25>> q;
	q.push(table);
	int deep = 0;
	while(deep<=6) {
		cout<<deep<<endl;
		int size = q.size();
		for(int i=0; i<size; i++) {
			auto front = q.front();
			q.pop();
			if(front==target) {
				cout<<deep<<endl;
				return 0;
			}
			for(int x=0; x<5; x++) {
				for(int y=0; y<5; y++) {
					q.push(turn(x, y, front));
				}
			}
		}
		deep++;
	}
	cout<<-1<<endl;
}
